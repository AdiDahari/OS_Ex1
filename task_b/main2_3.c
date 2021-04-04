#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

int main()
{
    __pid_t pid = fork();

    if (pid == 0)
    {
        chdir("/");
        setsid();
        close(stderr);
        close(stdin);
        close(stdout);

        openlog("daemonLog", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Daemon started\n");
        usleep(3000000);
        syslog(LOG_NOTICE, "Daemon working...\n");
        usleep(3000000);
        syslog(LOG_NOTICE, "Daemon finished\n");
    }
    else
    {
        printf("Daemon's PID: %d\n", pid);
    }
    return 0;
}