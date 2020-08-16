#include "bitonicSort128.h"


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

void ThirtyTwoInSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
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

void SixtyFourInSmallFir(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, const din_t &x32, const din_t &x33, const din_t &x34, const din_t &x35, const din_t &x36, const din_t &x37,
                     const din_t &x38, const din_t &x39, const din_t &x40, const din_t &x41, const din_t &x42, const din_t &x43, const din_t &x44, 
                     const din_t &x45, const din_t &x46, const din_t &x47, const din_t &x48, const din_t &x49, const din_t &x50, const din_t &x51, const din_t &x52, const din_t &x53,
                     const din_t &x54, const din_t &x55, const din_t &x56, const din_t &x57, const din_t &x58, const din_t &x59, const din_t &x60, 
                     const din_t &x61, const din_t &x62, const din_t &x63, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31, din_t &y32, din_t &y33, din_t &y34, din_t &y35, din_t &y36, din_t &y37, din_t &y38, 
                    din_t &y39, din_t &y40, din_t &y41, din_t &y42, din_t &y43, din_t &y44, din_t &y45, din_t &y46, din_t &y47, din_t &y48, din_t &y49, din_t &y50, din_t &y51, din_t &y52, din_t &y53, din_t &y54, 
                    din_t &y55, din_t &y56, din_t &y57, din_t &y58, din_t &y59, din_t &y60, din_t &y61, din_t &y62, din_t &y63){

        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res15;

        res15 = AscendDescend(x0, x32);
        y0 = res15.smaller; y32 = res15.greater;

        res15 = AscendDescend(x1, x33);
        y1 = res15.smaller; y33 = res15.greater;

        res15 = AscendDescend(x2, x34);
        y2 = res15.smaller; y34 = res15.greater;

        res15 = AscendDescend(x3, x35);
        y3 = res15.smaller; y35 = res15.greater;

        res15 = AscendDescend(x4, x36);
        y4 = res15.smaller; y36 = res15.greater;

        res15 = AscendDescend(x5, x37);
        y5 = res15.smaller; y37 = res15.greater;

        res15 = AscendDescend(x6, x38);
        y6 = res15.smaller; y38 = res15.greater;

        res15 = AscendDescend(x7, x39);
        y7 = res15.smaller; y39 = res15.greater;

        res15 = AscendDescend(x8, x40);
        y8 = res15.smaller; y40 = res15.greater;

        res15 = AscendDescend(x9, x41);
        y9 = res15.smaller; y41 = res15.greater;

        res15 = AscendDescend(x10, x42);
        y10 = res15.smaller; y42 = res15.greater;

        res15 = AscendDescend(x11, x43);
        y11 = res15.smaller; y43 = res15.greater;

        res15 = AscendDescend(x12, x44);
        y12 = res15.smaller; y44 = res15.greater;

        res15 = AscendDescend(x13, x45);
        y13 = res15.smaller; y45 = res15.greater;

        res15 = AscendDescend(x14, x46);
        y14 = res15.smaller; y46 = res15.greater;

        res15 = AscendDescend(x15, x47);
        y15 = res15.smaller; y47 = res15.greater;

        res15 = AscendDescend(x16, x48);
        y16 = res15.smaller; y48 = res15.greater;

        res15 = AscendDescend(x17, x49);
        y17 = res15.smaller; y49 = res15.greater;

        res15 = AscendDescend(x18, x50);
        y18 = res15.smaller; y50 = res15.greater;

        res15 = AscendDescend(x19, x51);
        y19 = res15.smaller; y51 = res15.greater;

        res15 = AscendDescend(x20, x52);
        y20 = res15.smaller; y52 = res15.greater;

        res15 = AscendDescend(x21, x53);
        y21 = res15.smaller; y53 = res15.greater;

        res15 = AscendDescend(x22, x54);
        y22 = res15.smaller; y54 = res15.greater;

        res15 = AscendDescend(x23, x55);
        y23 = res15.smaller; y55 = res15.greater;

        res15 = AscendDescend(x24, x56);
        y24 = res15.smaller; y56 = res15.greater;

        res15 = AscendDescend(x25, x57);
        y25 = res15.smaller; y57 = res15.greater;

        res15 = AscendDescend(x26, x58);
        y26 = res15.smaller; y58 = res15.greater;

        res15 = AscendDescend(x27, x59);
        y27 = res15.smaller; y59 = res15.greater;

        res15 = AscendDescend(x28, x60);
        y28 = res15.smaller; y60 = res15.greater;

        res15 = AscendDescend(x29, x61);
        y29 = res15.smaller; y61 = res15.greater;

        res15 = AscendDescend(x30, x62);
        y30 = res15.smaller; y62 = res15.greater;

        res15 = AscendDescend(x31, x63);
        y31 = res15.smaller; y63 = res15.greater;
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

        res8 = AscendDescend(x1, x3);
        y1 = res8.smaller; y3 = res8.greater;
}

void EightinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7){
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res9;
        res9 = AscendDescend(x0, x4);
        y0 = res9.greater; y4 = res9.smaller;

        res9 = AscendDescend(x1, x5);
        y1 = res9.greater; y5 = res9.smaller;

        res9 = AscendDescend(x2, x6);
        y2 = res9.greater; y6 = res9.smaller;

        res9 = AscendDescend(x3, x7);
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

        res10 = AscendDescend(x10, x14);
        y10 = res10.smaller; y14 = res10.greater;

        res10 = AscendDescend(x11, x15);
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

void ThirtyTwoInSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31){
                    
        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res14;

        res14 = AscendDescend(x0, x16);
        y0 = res14.greater; y16 = res14.smaller;

        res14 = AscendDescend(x1, x17);
        y1 = res14.greater; y17 = res14.smaller;

        res14 = AscendDescend(x2, x18);
        y2 = res14.greater; y18 = res14.smaller;

        res14 = AscendDescend(x3, x19);
        y3 = res14.greater; y19 = res14.smaller;

        res14 = AscendDescend(x4, x20);
        y4 = res14.greater; y20 = res14.smaller;

        res14 = AscendDescend(x5, x21);
        y5 = res14.greater; y21 = res14.smaller;

        res14 = AscendDescend(x6, x22);
        y6 = res14.greater; y22 = res14.smaller;

        res14 = AscendDescend(x7, x23);
        y7 = res14.greater; y23 = res14.smaller;

        res14 = AscendDescend(x8, x24);
        y8 = res14.greater; y24 = res14.smaller;

        res14 = AscendDescend(x9, x25);
        y9 = res14.greater; y25 = res14.smaller;

        res14 = AscendDescend(x10, x26);
        y10 = res14.greater; y26 = res14.smaller;

        res14 = AscendDescend(x11, x27);
        y11 = res14.greater; y27 = res14.smaller;

        res14 = AscendDescend(x12, x28);
        y12 = res14.greater; y28 = res14.smaller;

        res14 = AscendDescend(x13, x29);
        y13 = res14.greater; y29 = res14.smaller;

        res14 = AscendDescend(x14, x30);
        y14 = res14.greater; y30 = res14.smaller;

        res14 = AscendDescend(x15, x31);
        y15 = res14.greater; y31 = res14.smaller;
}


