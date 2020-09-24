#include "bitonicSort64.h"


//Main CAE block (compare and exchange)
GreaterSmaller AscendDescend(const din_t &x, const din_t &y){
#pragma HLS PIPELINE II=9
#pragma HLS INLINE
    GreaterSmaller s;

    s.greater = (x > y) ? x : y;
    s.smaller = (x > y) ? y : x;

    return s;
}

//....................Increasing order function..........................//

void FourinSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res;
        res = AscendDescend(x0, x2);
        y0 = res.smaller; y2 = res.greater;

        res = AscendDescend(x1, x3);
        y1 = res.smaller; y3 = res.greater;
}

void FourinGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res;
        res = AscendDescend(x0, x2);
        y0 = res.greater; y2 = res.smaller;

        res = AscendDescend(x1, x3);
        y1 = res.greater; y3 = res.smaller;
}

void EightinSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;
        res = AscendDescend(x0, x4);
        y0 = res.smaller; y4 = res.greater;

        res = AscendDescend(x1, x5);
        y1 = res.smaller; y5 = res.greater;

        res = AscendDescend(x2, x6);
        y2 = res.smaller; y6 = res.greater;

        res = AscendDescend(x3, x7);
        y3 = res.smaller; y7 = res.greater;

}

void EightinGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
       	#pragma HLS INLINE
        GreaterSmaller res;
        res = AscendDescend(x0, x4);
        y0 = res.greater; y4 = res.smaller;

        res = AscendDescend(x1, x5);
        y1 = res.greater; y5 = res.smaller;

        res = AscendDescend(x2, x6);
        y2 = res.greater; y6 = res.smaller;

        res = AscendDescend(x3, x7);
        y3 = res.greater; y7 = res.smaller;

}

void SixteenSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
                     
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;

        res = AscendDescend(x0, x8);
        y0 = res.smaller; y8 = res.greater;

        res = AscendDescend(x1, x9);
        y1 = res.smaller; y9 = res.greater;

        res = AscendDescend(x2, x10);
        y2 = res.smaller; y10 = res.greater;

        res = AscendDescend(x3, x11);
        y3 = res.smaller; y11 = res.greater;

        res = AscendDescend(x4, x12);
        y4 = res.smaller; y12 = res.greater;

        res = AscendDescend(x5, x13);
        y5 = res.smaller; y13 = res.greater;

        res = AscendDescend(x6, x14);
        y6 = res.smaller; y14 = res.greater;

        res = AscendDescend(x7, x15);
        y7 = res.smaller; y15 = res.greater;
}

void SixteenGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;

        res = AscendDescend(x0, x8);
        y0 = res.greater; y8 = res.smaller;

        res = AscendDescend(x1, x9);
        y1 = res.greater; y9 = res.smaller;

        res = AscendDescend(x2, x10);
        y2 = res.greater; y10 = res.smaller;

        res = AscendDescend(x3, x11);
        y3 = res.greater; y11 = res.smaller;

        res = AscendDescend(x4, x12);
        y4 = res.greater; y12 = res.smaller;

        res = AscendDescend(x5, x13);
        y5 = res.greater; y13 = res.smaller;

        res = AscendDescend(x6, x14);
        y6 = res.greater; y14 = res.smaller;

        res = AscendDescend(x7, x15);
        y7 = res.greater; y15 = res.smaller;
}

//....................Decreasing order function..........................//

void FourinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res;
        res = AscendDescend(x0, x2);
        y0 = res.greater; y2 = res.smaller;

        res = AscendDescend(x1, x3);
        y1 = res.greater; y3 = res.smaller;
}

void FourinGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res;
        res = AscendDescend(x0, x2);
        y0 = res.smaller; y2 = res.greater;

        res = AscendDescend(x1, x3);
        y1 = res.smaller; y3 = res.greater;
}

void EightinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;
        res = AscendDescend(x0, x4);
        y0 = res.greater; y4 = res.smaller;

        res = AscendDescend(x1, x5);
        y1 = res.greater; y5 = res.smaller;

        res = AscendDescend(x2, x6);
        y2 = res.greater; y6 = res.smaller;

        res = AscendDescend(x3, x7);
        y3 = res.greater; y7 = res.smaller;

}

void EightinGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
       	#pragma HLS INLINE
        GreaterSmaller res;
        res = AscendDescend(x0, x4);
        y0 = res.smaller; y4 = res.greater;

        res = AscendDescend(x1, x5);
        y1 = res.smaller; y5 = res.greater;

        res = AscendDescend(x2, x6);
        y2 = res.smaller; y6 = res.greater;

        res = AscendDescend(x3, x7);
        y3 = res.smaller; y7 = res.greater;

}

void SixteenSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;

        res = AscendDescend(x0, x8);
        y0 = res.greater; y8 = res.smaller;

        res = AscendDescend(x1, x9);
        y1 = res.greater; y9 = res.smaller;

        res = AscendDescend(x2, x10);
        y2 = res.greater; y10 = res.smaller;

        res = AscendDescend(x3, x11);
        y3 = res.greater; y11 = res.smaller;

        res = AscendDescend(x4, x12);
        y4 = res.greater; y12 = res.smaller;

        res = AscendDescend(x5, x13);
        y5 = res.greater; y13 = res.smaller;

        res = AscendDescend(x6, x14);
        y6 = res.greater; y14 = res.smaller;

        res = AscendDescend(x7, x15);
        y7 = res.greater; y15 = res.smaller;
}

void SixteenGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;

        res = AscendDescend(x0, x8);
        y0 = res.smaller; y8 = res.greater;

        res = AscendDescend(x1, x9);
        y1 = res.smaller; y9 = res.greater;

        res = AscendDescend(x2, x10);
        y2 = res.smaller; y10 = res.greater;

        res = AscendDescend(x3, x11);
        y3 = res.smaller; y11 = res.greater;

        res = AscendDescend(x4, x12);
        y4 = res.smaller; y12 = res.greater;

        res = AscendDescend(x5, x13);
        y5 = res.smaller; y13 = res.greater;

        res = AscendDescend(x6, x14);
        y6 = res.smaller; y14 = res.greater;

        res = AscendDescend(x7, x15);
        y7 = res.smaller; y15 = res.greater;
}

void ThirtyTwoInSmallFir(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;

        res = AscendDescend(x0, x16);
        y0 = res.smaller; y16 = res.greater;

        res = AscendDescend(x1, x17);
        y1 = res.smaller; y17 = res.greater;

        res = AscendDescend(x2, x18);
        y2 = res.smaller; y18 = res.greater;

        res = AscendDescend(x3, x19);
        y3 = res.smaller; y19 = res.greater;

        res = AscendDescend(x4, x20);
        y4 = res.smaller; y20 = res.greater;

        res = AscendDescend(x5, x21);
        y5 = res.smaller; y21 = res.greater;

        res = AscendDescend(x6, x22);
        y6 = res.smaller; y22 = res.greater;

        res = AscendDescend(x7, x23);
        y7 = res.smaller; y23 = res.greater;

        res = AscendDescend(x8, x24);
        y8 = res.smaller; y24 = res.greater;

        res = AscendDescend(x9, x25);
        y9 = res.smaller; y25 = res.greater;

        res = AscendDescend(x10, x26);
        y10 = res.smaller; y26 = res.greater;

        res = AscendDescend(x11, x27);
        y11 = res.smaller; y27 = res.greater;

        res = AscendDescend(x12, x28);
        y12 = res.smaller; y28 = res.greater;

        res = AscendDescend(x13, x29);
        y13 = res.smaller; y29 = res.greater;

        res = AscendDescend(x14, x30);
        y14 = res.smaller; y30 = res.greater;

        res = AscendDescend(x15, x31);
        y15 = res.smaller; y31 = res.greater;
}
