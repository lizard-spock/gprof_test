#include <stdio.h>
#include <stdlib.h>
#include <sys/gmon.h>

void foo1() {
    for (int i = 0; i < 1000000; ++i);
}

void foo2() {
    for (int i = 0; i < 1000000; ++i);
}

int main() {
    foo1();
    printf("Hello, profiling!\n");

    // Start profiling
    monstartup((unsigned long)&foo2, (unsigned long)(&foo2 + 1));

    foo2();  // This call to foo() will be profiled

    // Stop profiling and cleanup
    _mcleanup();

    return 0;
}