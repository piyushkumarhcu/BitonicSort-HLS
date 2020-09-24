#ifndef _BITONICSORT256_H_
#define _BITONICSORT256_H_

#include <iostream>
#include "ap_int.h"
#define N 32
#define M 64
#define O 128
#define P 256

using namespace std;

typedef ap_uint<10> din_t;
typedef ap_uint<10> dloop_t;

class GreaterSmaller{
public:
    din_t greater, smaller;
};


//.........Main CAE block (compare and exchange)................//
GreaterSmaller AscendDescend(const din_t &x, const din_t &y); 

//....................Increasing order function..........................//
void FourinSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					        din_t &y0, din_t &y1, din_t &y2, din_t &y3);

void FourinGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					    din_t &y0, din_t &y1, din_t &y2, din_t &y3);

void EightinSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                        const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7);

void EightinGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                        const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7);

void SixteenSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                        const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                        const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15);

void SixteenGreatFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                        const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                        const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15);

void ThirtyTwoInSmallFirInc(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31); 

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
                    din_t &y55, din_t &y56, din_t &y57, din_t &y58, din_t &y59, din_t &y60, din_t &y61, din_t &y62, din_t &y63);                   

//....................Decreasing order function..........................//                
void FourinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3);

void FourinGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3,
					din_t &y0, din_t &y1, din_t &y2, din_t &y3);

void EightinSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7);

void EightinGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                const din_t &x6, const din_t &x7, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, din_t &y7);

void SixteenSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15);

void SixteenGreatFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15);

void ThirtyTwoInSmallFirDec(const din_t &x0, const din_t &x1, const din_t &x2, const din_t &x3, const din_t &x4, const din_t &x5,
                     const din_t &x6, const din_t &x7, const din_t &x8, const din_t &x9, const din_t &x10, const din_t &x11, const din_t &x12, 
                     const din_t &x13, const din_t &x14, const din_t &x15, const din_t &x16, const din_t &x17, const din_t &x18, const din_t &x19, const din_t &x20, const din_t &x21,
                     const din_t &x22, const din_t &x23, const din_t &x24, const din_t &x25, const din_t &x26, const din_t &x27, const din_t &x28, 
                     const din_t &x29, const din_t &x30, const din_t &x31, din_t &y0, din_t &y1, din_t &y2, din_t &y3, din_t &y4, din_t &y5, din_t &y6, 
                    din_t &y7, din_t &y8, din_t &y9, din_t &y10, din_t &y11, din_t &y12, din_t &y13, din_t &y14, din_t &y15, din_t &y16, din_t &y17, din_t &y18, din_t &y19, din_t &y20, din_t &y21, din_t &y22, 
                    din_t &y23, din_t &y24, din_t &y25, din_t &y26, din_t &y27, din_t &y28, din_t &y29, din_t &y30, din_t &y31); 

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
                    din_t &y55, din_t &y56, din_t &y57, din_t &y58, din_t &y59, din_t &y60, din_t &y61, din_t &y62, din_t &y63);

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
                    din_t &y119, din_t &y120, din_t &y121, din_t &y122, din_t &y123, din_t &y124, din_t &y125, din_t &y126, din_t &y127);   




void bitonic32Inc(din_t in1[N], din_t out1[N]);
void bitonic32Dec(din_t in2[N], din_t out2[N]);
void bitonicSort64Inc(din_t in3[M], din_t out3[M]);
void bitonicSort64Dec(din_t in4[M], din_t out4[M]);
void bitonicSort128Inc(din_t in5[O], din_t out5[O]);
void bitonicSort128Dec(din_t in6[O], din_t out6[O]);
void bitonicSort256(din_t in[P], din_t out[P]);

#endif



