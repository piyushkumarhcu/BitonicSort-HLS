#ifndef _BITONICSORT16_H_
#define _BITONICSORT16_H_

#include <iostream>
#include "ap_int.h"
#define N 16

using namespace std;

typedef ap_uint<32> din_t;
typedef ap_uint<6> dloop_t;

class GreaterSmaller{
public:
    din_t greater, smaller;
};

void bitonicSort16(din_t in[N], din_t out[N]);

#endif

