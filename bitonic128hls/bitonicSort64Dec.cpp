#include "bitonicSort128.h"

void bitonicSort64Dec(din_t in4[M], din_t out4[M]){
    #pragma HLS PIPELINE II=9

    #pragma HLS ARRAY_PARTITION variable=in4
    #pragma HLS ARRAY_PARTITION variable=out4

    GreaterSmaller result;

    din_t inX[N], inY[N], outX[N], outY[N];
    din_t r[M], s[M], t[M], u[M], v[M], w[M];

    #pragma HLS ARRAY_PARTITION variable=inX
    #pragma HLS ARRAY_PARTITION variable=inY
    #pragma HLS ARRAY_PARTITION variable=outX
    #pragma HLS ARRAY_PARTITION variable=outY
    #pragma HLS ARRAY_PARTITION variable=r
    #pragma HLS ARRAY_PARTITION variable=s
    #pragma HLS ARRAY_PARTITION variable=t
    #pragma HLS ARRAY_PARTITION variable=u
    #pragma HLS ARRAY_PARTITION variable=v
    #pragma HLS ARRAY_PARTITION variable=w


    for(dloop_t i=0; i<N; i++){
        #pragma HLS UNROLL
        inX[i] = in4[i];
        inY[i] = in4[i+N];
    }

    bitonic32Inc(inX, outX);
    bitonic32Dec(inY, outY);

    for(dloop_t i=0; i<N; i++){
        #pragma HLS UNROLL
        r[i] = outX[i];
        r[i+N] = outY[i];
    }

//.....................Starting first sorting stage.............................//

for(dloop_t i=0; i<M/2; i++){
    #pragma HLS UNROLL
    result = AscendDescend(r[i], r[i+M/2]);
    s[i] = result.greater; s[i+M/2] = result.smaller;
}

//.....................Starting second sorting stage............................//

for(dloop_t i=0; i<M/32; i++){
    #pragma HLS UNROLL
    ThirtyTwoInSmallFirDec(s[32*i], s[32*i+1], s[32*i+2], s[32*i+3], s[32*i+4], s[32*i+5], s[32*i+6], s[32*i+7],
                 s[32*i+8], s[32*i+9], s[32*i+10], s[32*i+11], s[32*i+12], s[32*i+13], s[32*i+14], s[32*i+15], s[32*i+16], 
                 s[32*i+17], s[32*i+18], s[32*i+19], s[32*i+20], s[32*i+21], s[32*i+22], s[32*i+23],
                 s[32*i+24], s[32*i+25], s[32*i+26], s[32*i+27], s[32*i+28], s[32*i+29], s[32*i+30], s[32*i+31], 
                 t[32*i], t[32*i+1], t[32*i+2], t[32*i+3], t[32*i+4], t[32*i+5], t[32*i+6], t[32*i+7],
                 t[32*i+8], t[32*i+9], t[32*i+10], t[32*i+11], t[32*i+12], t[32*i+13], t[32*i+14], t[32*i+15], 
                 t[32*i+16], t[32*i+17], t[32*i+18], t[32*i+19], t[32*i+20], t[32*i+21], t[32*i+22], t[32*i+23],
                 t[32*i+24], t[32*i+25], t[32*i+26], t[32*i+27], t[32*i+28], t[32*i+29], t[32*i+30], t[32*i+31]);
}

//.....................Starting third sorting stage..........................//

for(dloop_t i=0; i<M/16; i++){
    #pragma HLS UNROLL
    SixteenSmallFirDec(t[16*i], t[16*i+1], t[16*i+2], t[16*i+3], t[16*i+4], t[16*i+5], t[16*i+6], t[16*i+7],
                 t[16*i+8], t[16*i+9], t[16*i+10], t[16*i+11], t[16*i+12], t[16*i+13], t[16*i+14], t[16*i+15], 
                 u[16*i+0], u[16*i+1], u[16*i+2], u[16*i+3], u[16*i+4], u[16*i+5], u[16*i+6], u[16*i+7], u[16*i+8], 
                 u[16*i+9], u[16*i+10], u[16*i+11], u[16*i+12], u[16*i+13], u[16*i+14], u[16*i+15]);
}

//.....................Starting fourth sorting stage..........................//

for(dloop_t i=0; i<M/8; i++){
    #pragma HLS UNROLL
    EightinSmallFirDec(u[8*i], u[8*i+1], u[8*i+2], u[8*i+3], u[8*i+4], u[8*i+5], u[8*i+6], u[8*i+7],
                v[8*i], v[8*i+1], v[8*i+2], v[8*i+3], v[8*i+4], v[8*i+5], v[8*i+6], v[8*i+7]);
}

//.....................Starting fifth sorting stage............................//

for(dloop_t i=0; i<M/4; i++){
    #pragma HLS UNROLL
    FourinSmallFirDec(v[4*i], v[4*i+1], v[4*i+2], v[4*i+3], w[4*i], w[4*i+1], w[4*i+2], w[4*i+3]);
}

//.....................Starting sixth sorting stage..............................//

for(dloop_t i=0; i<M/2; i++){
    #pragma HLS UNROLL
    result = AscendDescend(w[2*i], w[2*i+1]);
    out4[2*i] = result.greater; out4[2*i+1] = result.smaller;
}

}
