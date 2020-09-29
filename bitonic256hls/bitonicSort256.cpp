#include "bitonicSort256.h"

void bitonicSort256(din_t in[P], din_t out[P]){
    #pragma HLS PIPELINE II=9

    #pragma HLS ARRAY_RESHAPE variable=in complete dim=1
    #pragma HLS ARRAY_RESHAPE variable=out complete dim=1

    GreaterSmaller result;

    din_t inX[O], inY[O], outX[O], outY[O];
    din_t r[P], s[P], t[P], u[P], v[P], w[P], x[P], y[P];

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
    #pragma HLS ARRAY_PARTITION variable=y

    for(dloop_t i=0; i<O; i++){
        #pragma HLS UNROLL
        inX[i] = in[i];
        inY[i] = in[i+O];
    }

    bitonicSort128Inc(inX, outX);
    bitonicSort128Dec(inY, outY);

    for(dloop_t i=0; i<O; i++){
        #pragma HLS UNROLL
        r[i] = outX[i];
        r[i+O] = outY[i];
    }

//.....................Starting firts sorting stage.............................//

for(dloop_t i=0; i<P/2; i++){
    #pragma HLS UNROLL
    result = AscendDescend(r[i], r[i+P/2]);
    s[i] = result.smaller; s[i+P/2] = result.greater;
}

//.....................Starting second sorting stage............................//

for(dloop_t i=0; i<P/128; i++){
    #pragma HLS UNROLL
   OneTwentyEightInSmallFir(s[128*i+0], s[128*i+1], s[128*i+2], s[128*i+3], s[128*i+4], s[128*i+5], s[128*i+6], s[128*i+7],
                        s[128*i+8], s[128*i+9], s[128*i+10], s[128*i+11], s[128*i+12], s[128*i+13], s[128*i+14], s[128*i+15], s[128*i+16], 
                        s[128*i+17], s[128*i+18], s[128*i+19], s[128*i+20], s[128*i+21], s[128*i+22], s[128*i+23],
                        s[128*i+24], s[128*i+25], s[128*i+26], s[128*i+27], s[128*i+28], s[128*i+29], s[128*i+30], s[128*i+31], s[128*i+32],
                        s[128*i+33], s[128*i+34], s[128*i+35], s[128*i+36], s[128*i+37], s[128*i+38], s[128*i+39],
                        s[128*i+40], s[128*i+41], s[128*i+42], s[128*i+43], s[128*i+44], s[128*i+45], s[128*i+46], s[128*i+47], s[128*i+48], 
                        s[128*i+49], s[128*i+50], s[128*i+51], s[128*i+52], s[128*i+53], s[128*i+54], s[128*i+55],
                        s[128*i+56], s[128*i+57], s[128*i+58], s[128*i+59], s[128*i+60], s[128*i+61], s[128*i+62], s[128*i+63], s[128*i+64], 
                        s[128*i+65], s[128*i+66], s[128*i+67], s[128*i+68], s[128*i+69], s[128*i+70], s[128*i+71],
                        s[128*i+72], s[128*i+73], s[128*i+74], s[128*i+75], s[128*i+76], s[128*i+77], s[128*i+78], s[128*i+79], s[128*i+80], 
                        s[128*i+81], s[128*i+82], s[128*i+83], s[128*i+84], s[128*i+85], s[128*i+86], s[128*i+87],
                        s[128*i+88], s[128*i+89], s[128*i+90], s[128*i+91], s[128*i+92], s[128*i+93], s[128*i+94], s[128*i+95], s[128*i+96],
                        s[128*i+97], s[128*i+98], s[128*i+99], s[128*i+100], s[128*i+101], s[128*i+102], s[128*i+103],
                        s[128*i+104], s[128*i+105], s[128*i+106], s[128*i+107], s[128*i+108], s[128*i+109], s[128*i+110], s[128*i+111], s[128*i+112], 
                        s[128*i+113], s[128*i+114], s[128*i+115], s[128*i+116], s[128*i+117], s[128*i+118], s[128*i+119],
                        s[128*i+120], s[128*i+121], s[128*i+122], s[128*i+123], s[128*i+124], s[128*i+125], s[128*i+126], s[128*i+127], 
                        t[128*i+0], t[128*i+1], t[128*i+2], t[128*i+3], t[128*i+4], t[128*i+5], t[128*i+6], t[128*i+7],
                        t[128*i+8], t[128*i+9], t[128*i+10], t[128*i+11], t[128*i+12], t[128*i+13], t[128*i+14], t[128*i+15], t[128*i+16], 
                        t[128*i+17], t[128*i+18], t[128*i+19], t[128*i+20], t[128*i+21], t[128*i+22], t[128*i+23],
                        t[128*i+24], t[128*i+25], t[128*i+26], t[128*i+27], t[128*i+28], t[128*i+29], t[128*i+30], t[128*i+31], t[128*i+32],
                        t[128*i+33], t[128*i+34], t[128*i+35], t[128*i+36], t[128*i+37], t[128*i+38], t[128*i+39],
                        t[128*i+40], t[128*i+41], t[128*i+42], t[128*i+43], t[128*i+44], t[128*i+45], t[128*i+46], t[128*i+47], t[128*i+48], 
                        t[128*i+49], t[128*i+50], t[128*i+51], t[128*i+52], t[128*i+53], t[128*i+54], t[128*i+55],
                        t[128*i+56], t[128*i+57], t[128*i+58], t[128*i+59], t[128*i+60], t[128*i+61], t[128*i+62], t[128*i+63], t[128*i+64], 
                        t[128*i+65], t[128*i+66], t[128*i+67], t[128*i+68], t[128*i+69], t[128*i+70], t[128*i+71],
                        t[128*i+72], t[128*i+73], t[128*i+74], t[128*i+75], t[128*i+76], t[128*i+77], t[128*i+78], t[128*i+79], t[128*i+80], 
                        t[128*i+81], t[128*i+82], t[128*i+83], t[128*i+84], t[128*i+85], t[128*i+86], t[128*i+87],
                        t[128*i+88], t[128*i+89], t[128*i+90], t[128*i+91], t[128*i+92], t[128*i+93], t[128*i+94], t[128*i+95], t[128*i+96],
                        t[128*i+97], t[128*i+98], t[128*i+99], t[128*i+100], t[128*i+101], t[128*i+102], t[128*i+103],
                        t[128*i+104], t[128*i+105], t[128*i+106], t[128*i+107], t[128*i+108], t[128*i+109], t[128*i+110], t[128*i+111], t[128*i+112], 
                        t[128*i+113], t[128*i+114], t[128*i+115], t[128*i+116], t[128*i+117], t[128*i+118], t[128*i+119],
                        t[128*i+120], t[128*i+121], t[128*i+122], t[128*i+123], t[128*i+124], t[128*i+125], t[128*i+126], t[128*i+127]);
}

//.....................Starting third sorting stage..........................//

for(dloop_t i=0; i<P/64; i++){
    #pragma HLS UNROLL
    SixtyFourInSmallFirInc(t[64*i+0], t[64*i+1], t[64*i+2], t[64*i+3], t[64*i+4], t[64*i+5], t[64*i+6], t[64*i+7],
                        t[64*i+8], t[64*i+9], t[64*i+10], t[64*i+11], t[64*i+12], t[64*i+13], t[64*i+14], t[64*i+15], t[64*i+16], 
                        t[64*i+17], t[64*i+18], t[64*i+19], t[64*i+20], t[64*i+21], t[64*i+22], t[64*i+23],
                        t[64*i+24], t[64*i+25], t[64*i+26], t[64*i+27], t[64*i+28], t[64*i+29], t[64*i+30], t[64*i+31], t[64*i+32],
                        t[64*i+33], t[64*i+34], t[64*i+35], t[64*i+36], t[64*i+37], t[64*i+38], t[64*i+39],
                        t[64*i+40], t[64*i+41], t[64*i+42], t[64*i+43], t[64*i+44], t[64*i+45], t[64*i+46], t[64*i+47], t[64*i+48], 
                        t[64*i+49], t[64*i+50], t[64*i+51], t[64*i+52], t[64*i+53], t[64*i+54], t[64*i+55],
                        t[64*i+56], t[64*i+57], t[64*i+58], t[64*i+59], t[64*i+60], t[64*i+61], t[64*i+62], t[64*i+63],
                        u[64*i+0], u[64*i+1], u[64*i+2], u[64*i+3], u[64*i+4], u[64*i+5], u[64*i+6], u[64*i+7],
                        u[64*i+8], u[64*i+9], u[64*i+10], u[64*i+11], u[64*i+12], u[64*i+13], u[64*i+14], u[64*i+15], 
                        u[64*i+16], u[64*i+17], u[64*i+18], u[64*i+19], u[64*i+20], u[64*i+21], u[64*i+22], u[64*i+23],
                        u[64*i+24], u[64*i+25], u[64*i+26], u[64*i+27], u[64*i+28], u[64*i+29], u[64*i+30], u[64*i+31], 
                        u[64*i+32], u[64*i+33], u[64*i+34], u[64*i+35], u[64*i+36], u[64*i+37], u[64*i+38], u[64*i+39],
                        u[64*i+40], u[64*i+41], u[64*i+42], u[64*i+43], u[64*i+44], u[64*i+45], u[64*i+46], u[64*i+47], 
                        u[64*i+48], u[64*i+49], u[64*i+50], u[64*i+51], u[64*i+52], u[64*i+53], u[64*i+54], u[64*i+55],
                        u[64*i+56], u[64*i+57], u[64*i+58], u[64*i+59], u[64*i+60], u[64*i+61], u[64*i+62], u[64*i+63]);
}

//.....................Starting fourth sorting stage..........................//

for(dloop_t i=0; i<P/32; i++){
    #pragma HLS UNROLL
    ThirtyTwoInSmallFirInc(u[32*i], u[32*i+1], u[32*i+2], u[32*i+3], u[32*i+4], u[32*i+5], u[32*i+6], u[32*i+7],
                            u[32*i+8], u[32*i+9], u[32*i+10], u[32*i+11], u[32*i+12], u[32*i+13], u[32*i+14], u[32*i+15], u[32*i+16], 
                            u[32*i+17], u[32*i+18], u[32*i+19], u[32*i+20], u[32*i+21], u[32*i+22], u[32*i+23],
                            u[32*i+24], u[32*i+25], u[32*i+26], u[32*i+27], u[32*i+28], u[32*i+29], u[32*i+30], u[32*i+31], 
                            v[32*i+0], v[32*i+1], v[32*i+2], v[32*i+3], v[32*i+4], v[32*i+5], v[32*i+6], v[32*i+7], v[32*i+8], 
                            v[32*i+9], v[32*i+10], v[32*i+11], v[32*i+12], v[32*i+13], v[32*i+14], v[32*i+15], v[32*i+16], 
                            v[32*i+17], v[32*i+18], v[32*i+19], v[32*i+20], v[32*i+21], v[32*i+22], v[32*i+23], v[32*i+24], 
                            v[32*i+25], v[32*i+26], v[32*i+27], v[32*i+28], v[32*i+29], v[32*i+30], v[32*i+31]);
}

//.....................Starting fifth sorting stage............................//

for(dloop_t i=0; i<P/16; i++){
    #pragma HLS UNROLL
   SixteenSmallFirInc(v[16*i+0], v[16*i+1], v[16*i+2], v[16*i+3], v[16*i+4], v[16*i+5], v[16*i+6], v[16*i+7], 
                        v[16*i+8], v[16*i+9], v[16*i+10], v[16*i+11], v[16*i+12], v[16*i+13], v[16*i+14], v[16*i+15],
                        w[16*i+0], w[16*i+1], w[16*i+2], w[16*i+3], w[16*i+4], w[16*i+5], w[16*i+6], w[16*i+7],
                        w[16*i+8], w[16*i+9], w[16*i+10], w[16*i+11], w[16*i+12], w[16*i+13], w[16*i+14], w[16*i+15]);
}

//.....................Starting sixth sorting stage..............................//

for(dloop_t i=0; i<P/8; i++){
    #pragma HLS UNROLL
    EightinSmallFirInc(w[8*i+0], w[8*i+1], w[8*i+2], w[8*i+3], w[8*i+4], w[8*i+5], w[8*i+6], w[8*i+7],
                         x[8*i+0], x[8*i+1], x[8*i+2], x[8*i+3], x[8*i+4], x[8*i+5], x[8*i+6], x[8*i+7]);
}

//.....................Starting seventh sorting stage..............................//

for(dloop_t i=0; i<P/4; i++){
    #pragma HLS UNROLL
    FourinSmallFirInc(x[4*i+0], x[4*i+1], x[4*i+2], x[4*i+3], y[4*i+0], y[4*i+1], y[4*i+2], y[4*i+3]);
}

//.....................Starting eighth sorting stage..............................//

for(dloop_t i=0; i<P/2; i++){
    #pragma HLS UNROLL
    result = AscendDescend(y[2*i], y[2*i+1]);
    out[2*i] = result.smaller; out[2*i+1] = result.greater;
}

}
