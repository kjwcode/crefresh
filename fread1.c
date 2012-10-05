#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


int
main(int argc, char **argv)
{
    FILE *ifh;
    size_t rb;
    char *buf;
    int ret;
    const size_t bufsize = 257;

    if (argc < 2) {
        fprintf(stderr, "Need command-line arg.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        ifh = fopen(argv[i], "r");
        if (ifh == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        printf("contents of %s:\n\n", argv[i]);
        
        buf = (char *)calloc(bufsize, 1);
        if (!buf) {
            fprintf(stderr, "Unable to allocate memory.\n\n");
            exit(EXIT_FAILURE);
        }

        while ((rb = fread(buf, 1, bufsize, ifh))) {
            printf("%s", buf);
            memset(buf, 0, bufsize);

            if (feof(ifh)) { break; }
        }

        free(buf);
        ret = fclose(ifh);
        if (ret == EOF) {
            perror("fclose");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}

