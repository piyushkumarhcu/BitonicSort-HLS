#include "bitonicSort128.h"

void bitonicSort128(din_t in[O], din_t out[O]){
    #pragma HLS PIPELINE II=9

    #pragma HLS ARRAY_PARTITION variable=in
    #pragma HLS ARRAY_PARTITION variable=out

    GreaterSmaller result;

    din_t inX[M], inY[M], outX[M], outY[M];
    din_t r[O], s[O], t[O], u[O], v[O], w[O], x[O];

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
    #pragma HLS ARRAY_PARTITION variable=x



    for(dloop_t i=0; i<M; i++){
        #pragma HLS UNROLL
        inX[i] = in[i];
        inY[i] = in[i+M];
    }

    bitonicSort64Inc(inX, outX);
    bitonicSort64Dec(inY, outY);

    for(dloop_t i=0; i<M; i++){
        #pragma HLS UNROLL
        r[i] = outX[i];
        r[i+M] = outY[i];
    }

//.....................Starting firts sorting stage.............................//

for(dloop_t i=0; i<O/2; i++){
    #pragma HLS UNROLL
    result = AscendDescend(r[i], r[i+O/2]);
    s[i] = result.smaller; s[i+O/2] = result.greater;
}

//.....................Starting second sorting stage............................//

for(dloop_t i=0; i<O/64; i++){
    #pragma HLS UNROLL
   SixtyFourInSmallFir(s[64*i+0], s[64*i+1], s[64*i+2], s[64*i+3], s[64*i+4], s[64*i+5], s[64*i+6], s[64*i+7],
                        s[64*i+8], s[64*i+9], s[64*i+10], s[64*i+11], s[64*i+12], s[64*i+13], s[64*i+14], s[64*i+15], s[64*i+16], 
                        s[64*i+17], s[64*i+18], s[64*i+19], s[64*i+20], s[64*i+21], s[64*i+22], s[64*i+23],
                        s[64*i+24], s[64*i+25], s[64*i+26], s[64*i+27], s[64*i+28], s[64*i+29], s[64*i+30], s[64*i+31], s[64*i+32],
                        s[64*i+33], s[64*i+34], s[64*i+35], s[64*i+36], s[64*i+37], s[64*i+38], s[64*i+39],
                        s[64*i+40], s[64*i+41], s[64*i+42], s[64*i+43], s[64*i+44], s[64*i+45], s[64*i+46], s[64*i+47], s[64*i+48], 
                        s[64*i+49], s[64*i+50], s[64*i+51], s[64*i+52], s[64*i+53], s[64*i+54], s[64*i+55],
                        s[64*i+56], s[64*i+57], s[64*i+58], s[64*i+59], s[64*i+60], s[64*i+61], s[64*i+62], s[64*i+63],
                        t[64*i+0], t[64*i+1], t[64*i+2], t[64*i+3], t[64*i+4], t[64*i+5], t[64*i+6], t[64*i+7],
                        t[64*i+8], t[64*i+9], t[64*i+10], t[64*i+11], t[64*i+12], t[64*i+13], t[64*i+14], t[64*i+15], 
                        t[64*i+16], t[64*i+17], t[64*i+18], t[64*i+19], t[64*i+20], t[64*i+21], t[64*i+22], t[64*i+23],
                        t[64*i+24], t[64*i+25], t[64*i+26], t[64*i+27], t[64*i+28], t[64*i+29], t[64*i+30], t[64*i+31], 
                        t[64*i+32], t[64*i+33], t[64*i+34], t[64*i+35], t[64*i+36], t[64*i+37], t[64*i+38], t[64*i+39],
                        t[64*i+40], t[64*i+41], t[64*i+42], t[64*i+43], t[64*i+44], t[64*i+45], t[64*i+46], t[64*i+47], 
                        t[64*i+48], t[64*i+49], t[64*i+50], t[64*i+51], t[64*i+52], t[64*i+53], t[64*i+54], t[64*i+55],
                        t[64*i+56], t[64*i+57], t[64*i+58], t[64*i+59], t[64*i+60], t[64*i+61], t[64*i+62], t[64*i+63]);
}

//.....................Starting third sorting stage..........................//

for(dloop_t i=0; i<O/32; i++){
    #pragma HLS UNROLL
    ThirtyTwoInSmallFirInc(t[32*i], t[32*i+1], t[32*i+2], t[32*i+3], t[32*i+4], t[32*i+5], t[32*i+6], t[32*i+7],
                            t[32*i+8], t[32*i+9], t[32*i+10], t[32*i+11], t[32*i+12], t[32*i+13], t[32*i+14], t[32*i+15], t[32*i+16], 
                            t[32*i+17], t[32*i+18], t[32*i+19], t[32*i+20], t[32*i+21], t[32*i+22], t[32*i+23],
                            t[32*i+24], t[32*i+25], t[32*i+26], t[32*i+27], t[32*i+28], t[32*i+29], t[32*i+30], t[32*i+31], 
                            u[32*i+0], u[32*i+1], u[32*i+2], u[32*i+3], u[32*i+4], u[32*i+5], u[32*i+6], u[32*i+7], u[32*i+8], 
                            u[32*i+9], u[32*i+10], u[32*i+11], u[32*i+12], u[32*i+13], u[32*i+14], u[32*i+15], u[32*i+16], 
                            u[32*i+17], u[32*i+18], u[32*i+19], u[32*i+20], u[32*i+21], u[32*i+22], u[32*i+23], u[32*i+24], 
                            u[32*i+25], u[32*i+26], u[32*i+27], u[32*i+28], u[32*i+29], u[32*i+30], u[32*i+31]);
}

//.....................Starting fourth sorting stage..........................//

for(dloop_t i=0; i<O/16; i++){
    #pragma HLS UNROLL
    SixteenSmallFirInc(u[16*i+0], u[16*i+1], u[16*i+2], u[16*i+3], u[16*i+4], u[16*i+5], u[16*i+6], u[16*i+7], 
                        u[16*i+8], u[16*i+9], u[16*i+10], u[16*i+11], u[16*i+12], u[16*i+13], u[16*i+14], u[16*i+15],
                        v[16*i+0], v[16*i+1], v[16*i+2], v[16*i+3], v[16*i+4], v[16*i+5], v[16*i+6], v[16*i+7],
                        v[16*i+8], v[16*i+9], v[16*i+10], v[16*i+11], v[16*i+12], v[16*i+13], v[16*i+14], v[16*i+15]);
}

//.....................Starting fifth sorting stage............................//

for(dloop_t i=0; i<O/8; i++){
    #pragma HLS UNROLL
    EightinSmallFirInc(v[8*i+0], v[8*i+1], v[8*i+2], v[8*i+3], v[8*i+4], v[8*i+5], v[8*i+6], v[8*i+7],
                         w[8*i+0], w[8*i+1], w[8*i+2], w[8*i+3], w[8*i+4], w[8*i+5], w[8*i+6], w[8*i+7]);
}

//.....................Starting sixth sorting stage..............................//

for(dloop_t i=0; i<O/4; i++){
    #pragma HLS UNROLL
    FourinSmallFirInc(w[4*i+0], w[4*i+1], w[4*i+2], w[4*i+3], x[4*i+0], x[4*i+1], x[4*i+2], x[4*i+3]);
}

//.....................Starting seventh sorting stage..............................//

for(dloop_t i=0; i<O/2; i++){
    #pragma HLS UNROLL
    result = AscendDescend(x[2*i], x[2*i+1]);
    out[2*i] = result.smaller; out[2*i+1] = result.greater;
}

}
