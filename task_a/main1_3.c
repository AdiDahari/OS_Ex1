#include <stdio.h>
#include <dlfcn.h>

void (*hello_ariel)(const char *);
int main()
{
    void *hdl = dlopen("./libHello.so", RTLD_LAZY);
    if (hdl == NULL)
    {
        printf("Could not open library");
        return 1;
        hello_ariel = (void (*)(const char *))dlsym(hdl, "hello_ariel");
    }
    hello_ariel = (void (*)(const char *))dlsym(hdl, "hello_ariel");
    if (hello_ariel == NULL)
    {
        printf("Could not find method");
        return 1;
    }
    hello_ariel("Ariel");

    return 0;
}