#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_func(const char *m)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", m);
        usleep(1000000);
    }
}

int main()
{
    __pid_t pid = fork();

    if (pid == 0)
    {
        pid = fork();
        (pid == 0) ? print_func("Grand-Child") : print_func("Child");
    }
    else
    {
        print_func("Parent");
    }

    return 0;
}