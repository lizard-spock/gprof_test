#include <stdio.h>
#include <stdlib.h>
#include <sys/gmon.h>

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


// Dummy function to mark the end of profiling
void end_profiling() {
}

int main() {
    foo1();
    printf("Hello, profiling!\n");

    // Start profiling before the second call to foo2()
    monstartup((unsigned long)&foo2, (unsigned long)&end_profiling);

    foo2();  // This call to foo2() will be profiled

    // Stop profiling and cleanup
    end_profiling();  // Mark the end of profiling

    foo1();  // This call to foo1() will not be profiled

    return 0;
}
