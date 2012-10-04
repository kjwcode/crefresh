#include <stdio.h>
#include <stdlib.h>


void
first_exit(void)
{
    printf("first_exit\n");
}


void
second_exit(void)
{
    printf("second_exit\n");
}


int
main(int argc, char **argv)
{
    /* first registered, last called */
    atexit(second_exit);
    atexit(first_exit);

    printf("now exiting...\n");

    exit(EXIT_SUCCESS);
}

