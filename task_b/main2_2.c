#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>

#define SIZE 10000
char stack[SIZE + 1];

void print_func(const char *m)
{
    for (int i = 0; i < 30; i++)
    {
        printf("%s\n", m);
        usleep(1000000);
    }
}

int child_func(void *p)
{
    print_func("Child Thread");
}

int main()
{
    int clone1 = clone(child_func, stack + SIZE, CLONE_PARENT, 0);
    int clone2 = clone(child_func, stack + SIZE, CLONE_PARENT, 0);

    printf("Clone #1 = %d\n", clone1);
    printf("Clone #2 = %d\n", clone2);
    print_func("Parent Thread");
    return 0;
}
