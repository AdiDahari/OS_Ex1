#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 10000
char stack[SIZE + 1];

int main2_1(void *p)
{
    printf("main2_1, ID: %d\n\n", getpid());
    char *a[2] = {"./main2_1", NULL};
    execvp(a[0], a);
    usleep(5000000);
}
int main2_2(void *p)
{
    printf("main2_2, ID: %d\n\n", getpid());
    char *a[2] = {"./main2_2", NULL};
    execvp(a[0], a);
    usleep(5000000);
}
int main2_3(void *p)
{
    printf("main2_3, ID: %d\n\n", getpid());
    char *a[2] = {"./main2_3", NULL};
    execvp(a[0], a);
    usleep(5000000);
}

int main()
{
    printf("main2_1\n");
    int m2_1 = clone(main2_1, stack + SIZE, 0, 0);

    printf("main2_2\n");
    int m2_2 = clone(main2_2, stack + SIZE, 0, 0);

    printf("main2_3\n");
    int m2_3 = clone(main2_3, stack + SIZE, 0, 0);

    usleep(30000000);
    printf("\n\nall mains finished\n");

    return 0;
}
