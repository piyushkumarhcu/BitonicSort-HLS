#include "bitonicSort.h"

//Main CAE block (compare and exchange)
GreaterSmaller AscendDescend(const din_t &x, const din_t &y){
#pragma HLS PIPELINE
#pragma HLS INLINE
    GreaterSmaller s;

    s.greater = (x > y) ? x : y;
    s.smaller = (x > y) ? y : x;

    return s;
}

void FourinSmallFir(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE
   #pragma HLS INLINE
    GreaterSmaller res1;
        res1 = AscendDescend(x0, x2);
        y0 = res1.smaller; y2 = res1.greater;

        res1 = AscendDescend(x1, x3);
        y1 = res1.smaller; y3 = res1.greater;
}

void FourinGreatFir(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE
   #pragma HLS INLINE
    GreaterSmaller res2;
        res2 = AscendDescend(x0, x2);
        y0 = res2.greater; y2 = res2.smaller;

        res2 = AscendDescend(x1, x3);
        y1 = res2.greater; y3 = res2.smaller;
}

void EightinSmallFir(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE
        #pragma HLS INLINE
        GreaterSmaller res3;
        res3 = AscendDescend(x0, x4);
        y0 = res3.smaller; y4 = res3.greater;

        res3 = AscendDescend(x1, x5);
        y1 = res3.smaller; y5 = res3.greater;

        res3 = AscendDescend(x2, x6);
        y2 = res3.smaller; y6 = res3.greater;

        res3 = AscendDescend(x3, x7);
        y3 = res3.smaller; y7 = res3.greater;

}

void EightinGreatFir(const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, const din_t &x13,
                const din_t &x14, const din_t &x15, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
        #pragma HLS PIPELINE
       	#pragma HLS INLINE
        GreaterSmaller res4;
        res4 = AscendDescend(x8, x12);
        y8 = res4.greater; y12 = res4.smaller;

        res4 = AscendDescend(x9, x13);
        y9 = res4.greater; y13 = res4.smaller;

        res4 = AscendDescend(x10, x14);
        y10 = res4.greater; y14 = res4.smaller;

        res4 = AscendDescend(x11, x15);
        y11 = res4.greater; y15= res4.smaller;

}

void bitonicSort16(din_t in[N], din_t out[N]){

#pragma HLS ARRAY_PARTITION variable=in
#pragma HLS ARRAY_PARTITION variable=out

GreaterSmaller result;

din_t a[N], b[N], c[N], d[N], e[N], f[N], g[N], h[N], l[N];
#pragma HLS ARRAY_PARTITION variable=a
#pragma HLS ARRAY_PARTITION variable=b
#pragma HLS ARRAY_PARTITION variable=c
#pragma HLS ARRAY_PARTITION variable=d
#pragma HLS ARRAY_PARTITION variable=e
#pragma HLS ARRAY_PARTITION variable=f
#pragma HLS ARRAY_PARTITION variable=g
#pragma HLS ARRAY_PARTITION variable=h
#pragma HLS ARRAY_PARTITION variable=l

//Starting of first stage

for(dloop_t i=0; i<N/4; i++){
    #pragma HLS unroll
    result = AscendDescend(in[4*i], in[4*i+1]);
    a[4*i] = result.smaller; a[4*i+1] = result.greater; 
}

for(dloop_t i=0; i<N/4; i++){
    #pragma HLS unroll
    result = AscendDescend(in[4*i+2], in[4*i+3]);
    a[4*i+2] = result.greater; a[4*i+3] = result.smaller; 
}

//Starting of second stage

for(dloop_t i=0; i<N/8; i++){
    #pragma HLS unroll
    FourinSmallFir(a[8*i], a[8*i+1], a[8*i+2], a[8*i+3], b[8*i], b[8*i+1], b[8*i+2], b[8*i+3]);
    FourinGreatFir(a[8*i+4], a[8*i+5], a[8*i+6], a[8*i+7], b[8*i+4], b[8*i+5], b[8*i+6], b[8*i+7]); 
}

//Starting of third stage

for(dloop_t i=0; i<N/8; i++){
    #pragma HLS unroll
    result = AscendDescend(b[8*i], b[8*i+1]);
    c[8*i] = result.smaller; c[8*i+1] = result.greater; 
 
    result = AscendDescend(b[8*i+2], b[8*i+3]);
    c[8*i+2] = result.smaller; c[8*i+3] = result.greater;
}

for(dloop_t i=0; i<N/8; i++){
    #pragma HLS unroll
    result = AscendDescend(b[8*i+4], b[8*i+5]);
    c[8*i+4] = result.greater; c[8*i+5] = result.smaller; 

    result = AscendDescend(b[8*i+6], b[8*i+7]);
    c[8*i+6] = result.greater; c[8*i+7] = result.smaller;
}

//Starting of fourth stage

EightinSmallFir(c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
EightinGreatFir(c[8], c[9], c[10], c[11], c[12], c[13], c[14], c[15], d[8], d[9], d[10], d[11], d[12], d[13], d[14], d[15]);

//Starting fifth stage

for(dloop_t i=0; i<N/8; i++){
    #pragma HLS unroll
    FourinSmallFir(d[4*i], d[4*i+1], d[4*i+2], d[4*i+3], e[4*i], e[4*i+1], e[4*i+2], e[4*i+3]);
}

for(dloop_t i=0; i<N/8; i++){
    #pragma HLS unroll
    FourinGreatFir(d[4*i+8], d[4*i+9], d[4*i+10], d[4*i+11], e[4*i+8], e[4*i+9], e[4*i+10], e[4*i+11]);
}

//Starting sixth stage

for(dloop_t i=0; i<N/4; i++)
{
    #pragma HLS unroll
    result = AscendDescend(e[2*i], e[2*i+1]);
    f[2*i] = result.smaller; f[2*i+1] = result.greater;
}

for(dloop_t i=0; i<N/4; i++){
    #pragma HLS unroll
    result = AscendDescend(e[2*i+8], e[2*i+9]);
    f[2*i+8] = result.greater; f[2*i+9] = result.smaller;
}

//Starting seventh stage

for(dloop_t i=0; i<N/2; i++){
    #pragma HLS unroll
    result = AscendDescend(f[i], f[i+8]);
    g[i] = result.smaller; g[i+8] = result.greater;
}

//starting eighth stage

for(dloop_t i=0; i<N/8; i++){
    #pragma HLS unroll
    EightinSmallFir(g[8*i], g[8*i+1], g[8*i+2], g[8*i+3], g[8*i+4], g[8*i+5], g[8*i+6], g[8*i+7],
                h[8*i], h[8*i+1], h[8*i+2], h[8*i+3], h[8*i+4], h[8*i+5], h[8*i+6], h[8*i+7]);
}

//starting ninth stage

for(dloop_t i=0; i<N/4; i++){
    #pragma HLS unroll
    FourinSmallFir(h[4*i], h[4*i+1], h[4*i+2], h[4*i+3], l[4*i], l[4*i+1], l[4*i+2], l[4*i+3]);
}

//starting tenth stage

for(dloop_t i=0; i<N/2; i++){
    #pragma HLS unroll
    result = AscendDescend(l[2*i], l[2*i+1]);
    out[2*i] = result.smaller; out[2*i+1] = result.greater;
}

}
