#include <stdio.h>
#include <stdlib.h>
#include <sys/gmon.h>
// extern "C" void moncontrol(int mode);

void foo1() {
    for (int i = 0; i < 10000000; ++i);
}

void foo3() {
    for (int i = 0; i < 1000000000; ++i);
}

void foo2() {
    for (int i = 0; i < 100000000; ++i);
    foo3();
}


int main() {
    // moncontrol(0);
    foo1();
    printf("Hello, profiling!\n");

    // Start profiling before the second call to foo2()
    // moncontrol(1);

    foo2();  // This call to foo2() will be profiled

    // Stop profiling and cleanup
    // moncontrol(0);

    foo1();  // This call to foo1() will not be profiled

    return 0;
}
