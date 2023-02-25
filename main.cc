
#include <iostream>
#include "timelog.h"

extern "C" {
    void TestMaxFLOPS(size_t loop);
}

int main(int argc, char **argv) {
    int count = atoi(argv[1]);
    double time_cost, perf;
    size_t loop = 0x60000000L;
    //warm up
    TestMaxFLOPS(loop);
    Timer timer;
    TestMaxFLOPS(loop);
    time_cost = timer.cost();
    // 8 = (128 / sizeof(float)) * (1 + 1)
    // 1e-6 = 1e3 * 1e-9
    perf = loop * 8 * count / time_cost * 1e-6;
    
    printf("TestMaxFLOPS time cost: %f ms\n", time_cost);
	printf("CPU Max FLOPS is: %.4lf GFLOPS.\n", perf);
    return 0;
}
