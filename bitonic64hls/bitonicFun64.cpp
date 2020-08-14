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
    GreaterSmaller res1;
        res1 = AscendDescend(x0, x2);
        y0 = res1.smaller; y2 = res1.greater;

        res1 = AscendDescend(x1, x3);
        y1 = res1.smaller; y3 = res1.greater;
}

void FourinGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res2;
        res2 = AscendDescend(x0, x2);
        y0 = res2.greater; y2 = res2.smaller;

        res2 = AscendDescend(x1, x3);
        y1 = res2.greater; y3 = res2.smaller;
}

void EightinSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
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

void EightinGreatFirInc(const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, const din_t &x13,
                const din_t &x14, const din_t &x15, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
        #pragma HLS PIPELINE II=9
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

void SixteenSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
                     
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res5;

        res5 = AscendDescend(x0, x8);
        y0 = res5.smaller; y8 = res5.greater;

        res5 = AscendDescend(x1, x9);
        y1 = res5.smaller; y9 = res5.greater;

        res5 = AscendDescend(x2, x10);
        y2 = res5.smaller; y10 = res5.greater;

        res5 = AscendDescend(x3, x11);
        y3 = res5.smaller; y11 = res5.greater;

        res5 = AscendDescend(x4, x12);
        y4 = res5.smaller; y12 = res5.greater;

        res5 = AscendDescend(x5, x13);
        y5 = res5.smaller; y13 = res5.greater;

        res5 = AscendDescend(x6, x14);
        y6 = res5.smaller; y14 = res5.greater;

        res5 = AscendDescend(x7, x15);
        y7 = res5.smaller; y15 = res5.greater;
}

void SixteenGreatFirInc(const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res6;

        res6 = AscendDescend(x16, x24);
        y16 = res6.greater; y24 = res6.smaller;

        res6 = AscendDescend(x17, x25);
        y17 = res6.greater; y25 = res6.smaller;

        res6 = AscendDescend(x18, x26);
        y18 = res6.greater; y26 = res6.smaller;

        res6 = AscendDescend(x19, x27);
        y19 = res6.greater; y27 = res6.smaller;

        res6 = AscendDescend(x20, x28);
        y20 = res6.greater; y28 = res6.smaller;

        res6 = AscendDescend(x21, x29);
        y21 = res6.greater; y29 = res6.smaller;

        res6 = AscendDescend(x22, x30);
        y22 = res6.greater; y30 = res6.smaller;

        res6 = AscendDescend(x23, x31);
        y23 = res6.greater; y31 = res6.smaller;
}

//....................Decreasing order function..........................//

void FourinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res7;
        res7 = AscendDescend(x0, x2);
        y0 = res7.greater; y2 = res7.smaller;

        res7 = AscendDescend(x1, x3);
        y1 = res7.greater; y3 = res7.smaller;
}

void FourinGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3){
   #pragma HLS PIPELINE II=9
   #pragma HLS INLINE
    GreaterSmaller res8;
        res8 = AscendDescend(x0, x2);
        y0 = res8.smaller; y2 = res8.greater;

        res2 = AscendDescend(x1, x3);
        y1 = res8.smaller; y3 = res8.greater;
}

void EightinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res9;
        res9 = AscendDescend(x0, x4);
        y0 = res9.greater; y4 = res9.smaller;

        res3 = AscendDescend(x1, x5);
        y1 = res9.greater; y5 = res9.smaller;

        res3 = AscendDescend(x2, x6);
        y2 = res9.greater; y6 = res9.smaller;

        res3 = AscendDescend(x3, x7);
        y3 = res9.greater; y7 = res9.smaller;

}

void EightinGreatFirDec(const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, const din_t &x13,
                const din_t &x14, const din_t &x15, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
        #pragma HLS PIPELINE II=9
       	#pragma HLS INLINE
        GreaterSmaller res10;
        res10 = AscendDescend(x8, x12);
        y8 = res10.smaller; y12 = res10.greater;

        res10 = AscendDescend(x9, x13);
        y9 = res10.smaller; y13 = res10.greater;

        res4 = AscendDescend(x10, x14);
        y10 = res10.smaller; y14 = res10.greater;

        res4 = AscendDescend(x11, x15);
        y11 = res10.smaller; y15= res10.greater;

}

void SixteenSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res11;

        res11 = AscendDescend(x0, x8);
        y0 = res11.greater; y8 = res11.smaller;

        res11 = AscendDescend(x1, x9);
        y1 = res11.greater; y9 = res11.smaller;

        res11 = AscendDescend(x2, x10);
        y2 = res11.greater; y10 = res11.smaller;

        res11 = AscendDescend(x3, x11);
        y3 = res11.greater; y11 = res11.smaller;

        res11 = AscendDescend(x4, x12);
        y4 = res11.greater; y12 = res11.smaller;

        res11 = AscendDescend(x5, x13);
        y5 = res11.greater; y13 = res11.smaller;

        res11 = AscendDescend(x6, x14);
        y6 = res11.greater; y14 = res11.smaller;

        res11 = AscendDescend(x7, x15);
        y7 = res11.greater; y15 = res11.smaller;
}

void SixteenGreatFirDec(const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res12;

        res12 = AscendDescend(x16, x24);
        y16 = res12.smaller; y24 = res12.greater;

        res12 = AscendDescend(x17, x25);
        y17 = res12.smaller; y25 = res12.greater;

        res12 = AscendDescend(x18, x26);
        y18 = res12.smaller; y26 = res12.greater;

        res12 = AscendDescend(x19, x27);
        y19 = res12.smaller; y27 = res12.greater;

        res12 = AscendDescend(x20, x28);
        y20 = res12.smaller; y28 = res12.greater;

        res12 = AscendDescend(x21, x29);
        y21 = res12.smaller; y29 = res12.greater;

        res12 = AscendDescend(x22, x30);
        y22 = res12.smaller; y30 = res12.greater;

        res12 = AscendDescend(x23, x31);
        y23 = res12.smaller; y31 = res12.greater;
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
        GreaterSmaller res13;

        res13 = AscendDescend(x0, x16);
        y0 = res13.smaller; y16 = res13.greater;

        res13 = AscendDescend(x1, x17);
        y1 = res13.smaller; y17 = res13.greater;

        res13 = AscendDescend(x2, x18);
        y2 = res13.smaller; y18 = res13.greater;

        res13 = AscendDescend(x3, x19);
        y3 = res13.smaller; y19 = res13.greater;

        res13 = AscendDescend(x4, x20);
        y4 = res13.smaller; y20 = res13.greater;

        res13 = AscendDescend(x5, x21);
        y5 = res13.smaller; y21 = res13.greater;

        res13 = AscendDescend(x6, x22);
        y6 = res13.smaller; y22 = res13.greater;

        res13 = AscendDescend(x7, x23);
        y7 = res13.smaller; y23 = res13.greater;

        res13 = AscendDescend(x8, x24);
        y8 = res13.smaller; y24 = res13.greater;

        res13 = AscendDescend(x9, x25);
        y9 = res13.smaller; y25 = res13.greater;

        res13 = AscendDescend(x10, x26);
        y10 = res13.smaller; y26 = res13.greater;

        res13 = AscendDescend(x11, x27);
        y11 = res13.smaller; y27 = res13.greater;

        res13 = AscendDescend(x12, x28);
        y12 = res13.smaller; y28 = res13.greater;

        res13 = AscendDescend(x13, x29);
        y13 = res13.smaller; y29 = res13.greater;

        res13 = AscendDescend(x14, x30);
        y14 = res13.smaller; y30 = res13.greater;

        res13 = AscendDescend(x15, x31);
        y15 = res13.smaller; y31 = res13.greater;
}
