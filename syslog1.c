#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <syslog.h>


int
main(int argc, char **argv)
{
    openlog(basename(argv[0]), LOG_PID, LOG_LOCAL0);
    syslog(LOG_ALERT, "Just a test log message.");
    closelog();

    return EXIT_SUCCESS;
}
