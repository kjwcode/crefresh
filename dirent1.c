#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int
main(int argc, char **argv)
{
    DIR *dh;
    struct dirent cur, *result;

    if (argc < 2) {
        fprintf(stderr, "Need command-line arg.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        printf("contents of %s:\n\n", argv[i]);

        dh = opendir(argv[i]);
        if (!dh) {
            fprintf(stderr, "Unable to open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        while ((readdir_r(dh, &cur, &result) == 0) && result) {
            printf("%s\n", cur.d_name);
        }

        printf("\n");
        fflush(stdout);
        closedir(dh);
    }
    
    return EXIT_SUCCESS;
}

