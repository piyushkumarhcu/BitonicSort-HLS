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

void ThirtyTwoInSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
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
        GreaterSmaller res;

        res = AscendDescend(x0, x32);
        y0 = res.smaller; y32 = res.greater;

        res = AscendDescend(x1, x33);
        y1 = res.smaller; y33 = res.greater;

        res = AscendDescend(x2, x34);
        y2 = res.smaller; y34 = res.greater;

        res = AscendDescend(x3, x35);
        y3 = res.smaller; y35 = res.greater;

        res = AscendDescend(x4, x36);
        y4 = res.smaller; y36 = res.greater;

        res = AscendDescend(x5, x37);
        y5 = res.smaller; y37 = res.greater;

        res = AscendDescend(x6, x38);
        y6 = res.smaller; y38 = res.greater;

        res = AscendDescend(x7, x39);
        y7 = res.smaller; y39 = res.greater;

        res = AscendDescend(x8, x40);
        y8 = res.smaller; y40 = res.greater;

        res = AscendDescend(x9, x41);
        y9 = res.smaller; y41 = res.greater;

        res = AscendDescend(x10, x42);
        y10 = res.smaller; y42 = res.greater;

        res = AscendDescend(x11, x43);
        y11 = res.smaller; y43 = res.greater;

        res = AscendDescend(x12, x44);
        y12 = res.smaller; y44 = res.greater;

        res = AscendDescend(x13, x45);
        y13 = res.smaller; y45 = res.greater;

        res = AscendDescend(x14, x46);
        y14 = res.smaller; y46 = res.greater;

        res = AscendDescend(x15, x47);
        y15 = res.smaller; y47 = res.greater;

        res = AscendDescend(x16, x48);
        y16 = res.smaller; y48 = res.greater;

        res = AscendDescend(x17, x49);
        y17 = res.smaller; y49 = res.greater;

        res = AscendDescend(x18, x50);
        y18 = res.smaller; y50 = res.greater;

        res = AscendDescend(x19, x51);
        y19 = res.smaller; y51 = res.greater;

        res = AscendDescend(x20, x52);
        y20 = res.smaller; y52 = res.greater;

        res = AscendDescend(x21, x53);
        y21 = res.smaller; y53 = res.greater;

        res = AscendDescend(x22, x54);
        y22 = res.smaller; y54 = res.greater;

        res = AscendDescend(x23, x55);
        y23 = res.smaller; y55 = res.greater;

        res = AscendDescend(x24, x56);
        y24 = res.smaller; y56 = res.greater;

        res = AscendDescend(x25, x57);
        y25 = res.smaller; y57 = res.greater;

        res = AscendDescend(x26, x58);
        y26 = res.smaller; y58 = res.greater;

        res = AscendDescend(x27, x59);
        y27 = res.smaller; y59 = res.greater;

        res = AscendDescend(x28, x60);
        y28 = res.smaller; y60 = res.greater;

        res = AscendDescend(x29, x61);
        y29 = res.smaller; y61 = res.greater;

        res = AscendDescend(x30, x62);
        y30 = res.smaller; y62 = res.greater;

        res = AscendDescend(x31, x63);
        y31 = res.smaller; y63 = res.greater;
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

void ThirtyTwoInSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
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
        y0 = res.greater; y16 = res.smaller;

        res = AscendDescend(x1, x17);
        y1 = res.greater; y17 = res.smaller;

        res = AscendDescend(x2, x18);
        y2 = res.greater; y18 = res.smaller;

        res = AscendDescend(x3, x19);
        y3 = res.greater; y19 = res.smaller;

        res = AscendDescend(x4, x20);
        y4 = res.greater; y20 = res.smaller;

        res = AscendDescend(x5, x21);
        y5 = res.greater; y21 = res.smaller;

        res = AscendDescend(x6, x22);
        y6 = res.greater; y22 = res.smaller;

        res = AscendDescend(x7, x23);
        y7 = res.greater; y23 = res.smaller;

        res = AscendDescend(x8, x24);
        y8 = res.greater; y24 = res.smaller;

        res = AscendDescend(x9, x25);
        y9 = res.greater; y25 = res.smaller;

        res = AscendDescend(x10, x26);
        y10 = res.greater; y26 = res.smaller;

        res = AscendDescend(x11, x27);
        y11 = res.greater; y27 = res.smaller;

        res = AscendDescend(x12, x28);
        y12 = res.greater; y28 = res.smaller;

        res = AscendDescend(x13, x29);
        y13 = res.greater; y29 = res.smaller;

        res = AscendDescend(x14, x30);
        y14 = res.greater; y30 = res.smaller;

        res = AscendDescend(x15, x31);
        y15 = res.greater; y31 = res.smaller;
}


