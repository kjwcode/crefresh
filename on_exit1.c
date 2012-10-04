#include <stdio.h>
#include <stdlib.h>


int
first_exit(void)
{
    printf("first_exit\n");

    return EXIT_SUCCESS;
}


int
second_exit(void)
{
    printf("second_exit\n");

    return EXIT_SUCCESS;
}


int
main(int argc, char **argv)
{
    /* as with atexit(), first registered is last called */
    on_exit((void *)second_exit, "");
    on_exit((void *)first_exit, "");

    return EXIT_SUCCESS;
}

