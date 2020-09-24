#include "bitonicSort256.h"


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

void SixtyFourInSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
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


void OneTwentyEightInSmallFir(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, const din_t &x32, const din_t &x33, const din_t &x34, const din_t &x35, const din_t &x36, const din_t &x37,
                     const din_t &x38, const din_t &x39, const din_t &x40, const din_t &x41, const din_t &x42, const din_t &x43, const din_t &x44, 
                     const din_t &x45, const din_t &x46, const din_t &x47, const din_t &x48, const din_t &x49, const din_t &x50, const din_t &x51, const din_t &x52, const din_t &x53,
                     const din_t &x54, const din_t &x55, const din_t &x56, const din_t &x57, const din_t &x58, const din_t &x59, const din_t &x60, 
                     const din_t &x61, const din_t &x62, const din_t &x63, const din_t &x64, const din_t &x65, const din_t &x66, const din_t &x67, const din_t &x68, const din_t &x69,
                     const din_t &x70, const din_t &x71, const din_t &x72, const din_t &x73, const din_t &x74, const din_t &x75, const din_t &x76, 
                     const din_t &x77, const din_t &x78, const din_t &x79, const din_t &x80, const din_t &x81, const din_t &x82, const din_t &x83, const din_t &x84, const din_t &x85,
                     const din_t &x86, const din_t &x87, const din_t &x88, const din_t &x89, const din_t &x90, const din_t &x91, const din_t &x92, 
                     const din_t &x93, const din_t &x94, const din_t &x95, const din_t &x96, const din_t &x97, const din_t &x98, const din_t &x99, const din_t &x100, const din_t &x101,
                     const din_t &x102, const din_t &x103, const din_t &x104, const din_t &x105, const din_t &x106, const din_t &x107, const din_t &x108, 
                     const din_t &x109, const din_t &x110, const din_t &x111, const din_t &x112, const din_t &x113, const din_t &x114, const din_t &x115, const din_t &x116, const din_t &x117,
                     const din_t &x118, const din_t &x119, const din_t &x120, const din_t &x121, const din_t &x122, const din_t &x123, const din_t &x124, 
                     const din_t &x125, const din_t &x126, const din_t &x127, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31, din_t &y32, din_t &y33, din_t &y34, din_t &y35, din_t &y36, din_t &y37, din_t &y38, 
                    din_t &y39, din_t &y40, din_t &y41, din_t &y42, din_t &y43, din_t &y44, din_t &y45, din_t &y46, din_t &y47, din_t &y48, din_t &y49, din_t &y50, din_t &y51, din_t &y52, din_t &y53, din_t &y54, 
                    din_t &y55, din_t &y56, din_t &y57, din_t &y58, din_t &y59, din_t &y60, din_t &y61, din_t &y62, din_t &y63, din_t &y64, din_t &y65, din_t &y66, din_t &y67, din_t &y68, din_t &y69, din_t &y70, 
                    din_t &y71, din_t &y72, din_t &y73, din_t &y74, din_t &y75, din_t &y76, din_t &y77, din_t &y78, din_t &y79, din_t &y80, din_t &y81, din_t &y82, din_t &y83, din_t &y84, din_t &y85, din_t &y86, 
                    din_t &y87, din_t &y88, din_t &y89, din_t &y90, din_t &y91, din_t &y92, din_t &y93, din_t &y94, din_t &y95, din_t &y96, din_t &y97, din_t &y98, din_t &y99, din_t &y100, din_t &y101, din_t &y102, 
                    din_t &y103, din_t &y104, din_t &y105, din_t &y106, din_t &y107, din_t &y108, din_t &y109, din_t &y110, din_t &y111, din_t &y112, din_t &y113, din_t &y114, din_t &y115, din_t &y116, din_t &y117, din_t &y118, 
                    din_t &y119, din_t &y120, din_t &y121, din_t &y122, din_t &y123, din_t &y124, din_t &y125, din_t &y126, din_t &y127){

        #pragma HLS PIPELINE II=9
        #pragma HLS INLINE
        GreaterSmaller res;

        res = AscendDescend(x0, x64);
        y0 = res.smaller; y64 = res.greater;

        res = AscendDescend(x1, x65);
        y1 = res.smaller; y65 = res.greater;

        res = AscendDescend(x2, x66);
        y2 = res.smaller; y66 = res.greater;

        res = AscendDescend(x3, x67);
        y3 = res.smaller; y67 = res.greater;

        res = AscendDescend(x4, x68);
        y4 = res.smaller; y68 = res.greater;

        res = AscendDescend(x5, x69);
        y5 = res.smaller; y69 = res.greater;

        res = AscendDescend(x6, x70);
        y6 = res.smaller; y70 = res.greater;

        res = AscendDescend(x7, x71);
        y7 = res.smaller; y71 = res.greater;

        res = AscendDescend(x8, x72);
        y8 = res.smaller; y72 = res.greater;

        res = AscendDescend(x9, x73);
        y9 = res.smaller; y73 = res.greater;

        res = AscendDescend(x10, x74);
        y10 = res.smaller; y74 = res.greater;

        res = AscendDescend(x11, x75);
        y11 = res.smaller; y75 = res.greater;

        res = AscendDescend(x12, x76);
        y12 = res.smaller; y76 = res.greater;

        res = AscendDescend(x13, x77);
        y13 = res.smaller; y77 = res.greater;

        res = AscendDescend(x14, x78);
        y14 = res.smaller; y78 = res.greater;

        res = AscendDescend(x15, x79);
        y15 = res.smaller; y79 = res.greater;

        res = AscendDescend(x16, x80);
        y16 = res.smaller; y80 = res.greater;

        res = AscendDescend(x17, x81);
        y17 = res.smaller; y81 = res.greater;

        res = AscendDescend(x18, x82);
        y18 = res.smaller; y82 = res.greater;

        res = AscendDescend(x19, x83);
        y19 = res.smaller; y83 = res.greater;

        res = AscendDescend(x20, x84);
        y20 = res.smaller; y84 = res.greater;

        res = AscendDescend(x21, x85);
        y21 = res.smaller; y85 = res.greater;

        res = AscendDescend(x22, x86);
        y22 = res.smaller; y86 = res.greater;

        res = AscendDescend(x23, x87);
        y23 = res.smaller; y87 = res.greater;

        res = AscendDescend(x24, x88);
        y24 = res.smaller; y88 = res.greater;

        res = AscendDescend(x25, x89);
        y25 = res.smaller; y89 = res.greater;

        res = AscendDescend(x26, x90);
        y26 = res.smaller; y90 = res.greater;

        res = AscendDescend(x27, x91);
        y27 = res.smaller; y91 = res.greater;

        res = AscendDescend(x28, x92);
        y28 = res.smaller; y92 = res.greater;

        res = AscendDescend(x29, x93);
        y29 = res.smaller; y93 = res.greater;

        res = AscendDescend(x30, x94);
        y30 = res.smaller; y94 = res.greater;

        res = AscendDescend(x31, x95);
        y31 = res.smaller; y95 = res.greater;

        res = AscendDescend(x32, x96);
        y32 = res.smaller; y96 = res.greater;

        res = AscendDescend(x33, x97);
        y33 = res.smaller; y97 = res.greater;

        res = AscendDescend(x34, x98);
        y34 = res.smaller; y98 = res.greater;

        res = AscendDescend(x35, x99);
        y35 = res.smaller; y99 = res.greater;

        res = AscendDescend(x36, x100);
        y36 = res.smaller; y100 = res.greater;

        res = AscendDescend(x37, x101);
        y37 = res.smaller; y101 = res.greater;

        res = AscendDescend(x38, x102);
        y38 = res.smaller; y102 = res.greater;

        res = AscendDescend(x39, x103);
        y39 = res.smaller; y103 = res.greater;

        res = AscendDescend(x40, x104);
        y40 = res.smaller; y104 = res.greater;

        res = AscendDescend(x41, x105);
        y41 = res.smaller; y105 = res.greater;

        res = AscendDescend(x42, x106);
        y42 = res.smaller; y106 = res.greater;

        res = AscendDescend(x43, x107);
        y43 = res.smaller; y107 = res.greater;

        res = AscendDescend(x44, x108);
        y44 = res.smaller; y108 = res.greater;

        res = AscendDescend(x45, x109);
        y45 = res.smaller; y109 = res.greater;

        res = AscendDescend(x46, x110);
        y46 = res.smaller; y110 = res.greater;

        res = AscendDescend(x47, x111);
        y47 = res.smaller; y111 = res.greater;

        res = AscendDescend(x48, x112);
        y48 = res.smaller; y112 = res.greater;

        res = AscendDescend(x49, x113);
        y49 = res.smaller; y113 = res.greater;

        res = AscendDescend(x50, x114);
        y50 = res.smaller; y114 = res.greater;

        res = AscendDescend(x51, x115);
        y51 = res.smaller; y115 = res.greater;

        res = AscendDescend(x52, x116);
        y52 = res.smaller; y116 = res.greater;

        res = AscendDescend(x53, x117);
        y53 = res.smaller; y117 = res.greater;

        res = AscendDescend(x54, x118);
        y54 = res.smaller; y118 = res.greater;

        res = AscendDescend(x55, x119);
        y55 = res.smaller; y119 = res.greater;

        res = AscendDescend(x56, x120);
        y56 = res.smaller; y120 = res.greater;

        res = AscendDescend(x57, x121);
        y57 = res.smaller; y121 = res.greater;

        res = AscendDescend(x58, x122);
        y58 = res.smaller; y122 = res.greater;

        res = AscendDescend(x59, x123);
        y59 = res.smaller; y123 = res.greater;

        res = AscendDescend(x60, x124);
        y60 = res.smaller; y124 = res.greater;

        res = AscendDescend(x61, x125);
        y61 = res.smaller; y125 = res.greater;

        res = AscendDescend(x62, x126);
        y62 = res.smaller; y126 = res.greater;

        res = AscendDescend(x63, x127);
        y63 = res.smaller; y127 = res.greater;

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

void SixtyFourInSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
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
        y0 = res.greater; y32 = res.smaller;

        res = AscendDescend(x1, x33);
        y1 = res.greater; y33 = res.smaller;

        res = AscendDescend(x2, x34);
        y2 = res.greater; y34 = res.smaller;

        res = AscendDescend(x3, x35);
        y3 = res.greater; y35 = res.smaller;

        res = AscendDescend(x4, x36);
        y4 = res.greater; y36 = res.smaller;

        res = AscendDescend(x5, x37);
        y5 = res.greater; y37 = res.smaller;

        res = AscendDescend(x6, x38);
        y6 = res.greater; y38 = res.smaller;

        res = AscendDescend(x7, x39);
        y7 = res.greater; y39 = res.smaller;

        res = AscendDescend(x8, x40);
        y8 = res.greater; y40 = res.smaller;

        res = AscendDescend(x9, x41);
        y9 = res.greater; y41 = res.smaller;

        res = AscendDescend(x10, x42);
        y10 = res.greater; y42 = res.smaller;

        res = AscendDescend(x11, x43);
        y11 = res.greater; y43 = res.smaller;

        res = AscendDescend(x12, x44);
        y12 = res.greater; y44 = res.smaller;

        res = AscendDescend(x13, x45);
        y13 = res.greater; y45 = res.smaller;

        res = AscendDescend(x14, x46);
        y14 = res.greater; y46 = res.smaller;

        res = AscendDescend(x15, x47);
        y15 = res.greater; y47 = res.smaller;

        res = AscendDescend(x16, x48);
        y16 = res.greater; y48 = res.smaller;

        res = AscendDescend(x17, x49);
        y17 = res.greater; y49 = res.smaller;

        res = AscendDescend(x18, x50);
        y18 = res.greater; y50 = res.smaller;

        res = AscendDescend(x19, x51);
        y19 = res.greater; y51 = res.smaller;

        res = AscendDescend(x20, x52);
        y20 = res.greater; y52 = res.smaller;

        res = AscendDescend(x21, x53);
        y21 = res.greater; y53 = res.smaller;

        res = AscendDescend(x22, x54);
        y22 = res.greater; y54 = res.smaller;

        res = AscendDescend(x23, x55);
        y23 = res.greater; y55 = res.smaller;

        res = AscendDescend(x24, x56);
        y24 = res.greater; y56 = res.smaller;

        res = AscendDescend(x25, x57);
        y25 = res.greater; y57 = res.smaller;

        res = AscendDescend(x26, x58);
        y26 = res.greater; y58 = res.smaller;

        res = AscendDescend(x27, x59);
        y27 = res.greater; y59 = res.smaller;

        res = AscendDescend(x28, x60);
        y28 = res.greater; y60 = res.smaller;

        res = AscendDescend(x29, x61);
        y29 = res.greater; y61 = res.smaller;

        res = AscendDescend(x30, x62);
        y30 = res.greater; y62 = res.smaller;

        res = AscendDescend(x31, x63);
        y31 = res.greater; y63 = res.smaller;
}


