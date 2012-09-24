/*
Copyright (c) 2006-2009 Advanced Micro Devices, Inc. All Rights Reserved.
This software is subject to the Apache v2.0 License.
*/

#ifndef __FWJPEG_H__
#define __FWJPEG_H__

#include "fwBase.h"

//Data Structure define model
typedef struct EncodeHuffmanSpec  FwiEncodeHuffmanSpec;
typedef struct EncodeHuffmanState FwiEncodeHuffmanState;
typedef struct DecodeHuffmanSpec  FwiDecodeHuffmanSpec;
typedef struct DecodeHuffmanState FwiDecodeHuffmanState;

#ifdef __cplusplus
extern "C" {
#endif


////////////////////////////////////////////////////////////////
//                        GetLibVersion
////////////////////////////////////////////////////////////////


const FwLibraryVersion* STDCALL fwjGetLibVersion ();

////////////////////////////////////////////////////////////////
//                        RGBToY_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiRGBToY_JPEG_8u_P3C1R              ( const Fw8u * const pSrcRGB[3], int srcStep,
                                                                Fw8u *pDstY     , int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiRGBToY_JPEG_8u_C3C1R              ( const Fw8u *pSrcRGB   , int srcStep,
                                                                Fw8u *pDstY     , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        BGRToY_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiBGRToY_JPEG_8u_C3C1R              ( const Fw8u *pSrcBGR, int srcStep,
                                                                Fw8u *pDstY  , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        RGBToYCbCr_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiRGBToYCbCr_JPEG_8u_P3R            ( const Fw8u * const pSrcRGB[3]  , int srcStep,
                                                                Fw8u *pDstYCbCr[3], int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiRGBToYCbCr_JPEG_8u_C3P3R          ( const Fw8u *pSrcRGB     , int srcStep,
                                                                Fw8u * const pDstYCbCr[3], int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        YCbCrToRGB_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCbCrToRGB_JPEG_8u_P3R            ( const Fw8u * const pSrcYCbCr[3], int srcStep,
                                                                Fw8u *pDstRGB[3]  , int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiYCbCrToRGB_JPEG_8u_P3C3R          ( const Fw8u * const pSrcYCbCr[3], int srcStep,
                                                                Fw8u *pDstRGB     , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        RGB5X5ToYCbCr_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiRGB565ToYCbCr_JPEG_16u8u_C3P3R    ( const Fw16u *pSrcRGB     , int srcStep,
                                                                Fw8u  *pDstYCbCr[3], int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiRGB555ToYCbCr_JPEG_16u8u_C3P3R    ( const Fw16u *pSrcRGB     , int srcStep,
                                                                Fw8u  *pDstYCbCr[3], int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        YCbCrToRGB5X5_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCbCrToRGB565_JPEG_8u16u_P3C3R    ( const Fw8u  *pSrcYCbCr[3], int srcStep,
                                                                Fw16u *pDstRGB     , int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiYCbCrToRGB555_JPEG_8u16u_P3C3R    ( const Fw8u  *pSrcYCbCr[3], int srcStep,
                                                                Fw16u *pDstRGB     , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        BGRToYCbCr_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiBGRToYCbCr_JPEG_8u_C3P3R          ( const Fw8u *pSrcBGR     , int srcStep,
                                                                Fw8u * const pDstYCbCr[3], int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        YCbCrToBGR_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCbCrToBGR_JPEG_8u_P3C3R          ( const Fw8u * const pSrcYCbCr[3], int srcStep,
                                                                Fw8u *pDstBGR     , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        BGR5X5ToYCbCr_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiBGR565ToYCbCr_JPEG_16u8u_C3P3R    ( const Fw16u *pSrcBGR     , int srcStep,
                                                                Fw8u  *pDstYCbCr[3], int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiBGR555ToYCbCr_JPEG_16u8u_C3P3R    ( const Fw16u *pSrcBGR     , int srcStep,
                                                                Fw8u  *pDstYCbCr[3], int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        YCbCrToBGR5X5_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCbCrToBGR565_JPEG_8u16u_P3C3R    ( const Fw8u  *pSrcYCbCr[3], int srcStep,
                                                                Fw16u *pDstBGR     , int dstStep, FwiSize roiSize );

FwStatus STDCALL fwiYCbCrToBGR555_JPEG_8u16u_P3C3R    ( const Fw8u  *pSrcYCbCr[3], int srcStep,
                                                                Fw16u *pDstBGR     , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        CMYKToYCCK_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiCMYKToYCCK_JPEG_8u_P4R           ( const Fw8u * const pSrcCMYK[4], int srcStep,
                                                                Fw8u *pDstYCCK[4], int dstStep, FwiSize roiSize );

FwStatus STDCALL  fwiCMYKToYCCK_JPEG_8u_C4P4R         ( const Fw8u * const pSrcCMYK   , int srcStep,
                                                                Fw8u * const pDstYCCK[4], int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        YCCKToCMYK_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiYCCKToCMYK_JPEG_8u_P4R           ( const Fw8u * const pSrcYCCK[4], int srcStep,
                                                                Fw8u *pDstCMYK[4], int dstStep, FwiSize roiSize );

FwStatus STDCALL  fwiYCCKToCMYK_JPEG_8u_P4C4R         ( const Fw8u * const pSrcYCCK[4], int srcStep,
                                                                Fw8u *pDstCMYK   , int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        RGBToYCbCr444LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiRGBToYCbCr444LS_MCU_8u16s_C3P3R  ( const Fw8u  *pSrcRGB, int srcStep,
                                                                Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        RGBToYCbCr422LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiRGBToYCbCr422LS_MCU_8u16s_C3P3R  ( const Fw8u  *pSrcRGB, int srcStep,
                                                                Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        RGBToYCbCr411LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiRGBToYCbCr411LS_MCU_8u16s_C3P3R  ( const Fw8u  *pSrcRGB, int srcStep,
                                                                Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        BGRToYCbCr444LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiBGRToYCbCr444LS_MCU_8u16s_C3P3R      ( const Fw8u  *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL  fwiBGR565ToYCbCr444LS_MCU_16u16s_C3P3R  ( const Fw16u *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL  fwiBGR555ToYCbCr444LS_MCU_16u16s_C3P3R  ( const Fw16u *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        BGRToYCbCr422LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiBGRToYCbCr422LS_MCU_8u16s_C3P3R      ( const Fw8u  *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL  fwiBGR565ToYCbCr422LS_MCU_16u16s_C3P3R  ( const Fw16u *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL  fwiBGR555ToYCbCr422LS_MCU_16u16s_C3P3R  ( const Fw16u *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        BGRToYCbCr411LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiBGRToYCbCr411LS_MCU_8u16s_C3P3R      ( const Fw8u  *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL  fwiBGR565ToYCbCr411LS_MCU_16u16s_C3P3R  ( const Fw16u *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL  fwiBGR555ToYCbCr411LS_MCU_16u16s_C3P3R  ( const Fw16u *pSrcBGR, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        CMYKToYCCK444LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiCMYKToYCCK444LS_MCU_8u16s_C4P4R       ( const Fw8u  *pSrcCMYK, int srcStep,
                                                                    Fw16s *pDstMCU[4] );

////////////////////////////////////////////////////////////////
//                        CMYKToYCCK422LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiCMYKToYCCK422LS_MCU_8u16s_C4P4R       ( const Fw8u  *pSrcCMYK, int srcStep,
                                                                    Fw16s *pDstMCU[4] );

////////////////////////////////////////////////////////////////
//                        CMYKToYCCK411LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiCMYKToYCCK411LS_MCU_8u16s_C4P4R       ( const Fw8u  *pSrcCMYK, int srcStep,
                                                                    Fw16s *pDstMCU[4] );

////////////////////////////////////////////////////////////////
//                        YCbCr4XXToRGBLS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCbCr444ToRGBLS_MCU_16s8u_P3C3R       ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u *pDstRGB, int dstStep );

FwStatus STDCALL fwiYCbCr422ToRGBLS_MCU_16s8u_P3C3R       ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u *pDstRGB, int dstStep );

FwStatus STDCALL fwiYCbCr411ToRGBLS_MCU_16s8u_P3C3R       ( const Fw16s *pSrcMCU[3],
                                                                     Fw8u *pDstRGB, int dstStep );

////////////////////////////////////////////////////////////////
//                        YCbCr4XXLS_MCUToBGR
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCbCr444ToBGRLS_MCU_16s8u_P3C3R       ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr444ToBGR565LS_MCU_16s16u_P3C3R   ( const Fw16s *pSrcMCU[3],
                                                                    Fw16u *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr444ToBGR555LS_MCU_16s16u_P3C3R   ( const Fw16s *pSrcMCU[3],
                                                                    Fw16u *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr422ToBGRLS_MCU_16s8u_P3C3R       ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr422ToBGR565LS_MCU_16s16u_P3C3R   ( const Fw16s *pSrcMCU[3],
                                                                    Fw16u *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr422ToBGR555LS_MCU_16s16u_P3C3R   ( const Fw16s *pSrcMCU[3],
                                                                    Fw16u *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr411ToBGRLS_MCU_16s8u_P3C3R       ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr411ToBGR565LS_MCU_16s16u_P3C3R   ( const Fw16s *pSrcMCU[3],
                                                                    Fw16u *pDstBGR   , int dstStep );

FwStatus STDCALL fwiYCbCr411ToBGR555LS_MCU_16s16u_P3C3R   ( const Fw16s *pSrcMCU[3],
                                                                    Fw16u *pDstBGR   , int dstStep );

////////////////////////////////////////////////////////////////
//                        YCCK4XXToCMYKLS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiYCCK444ToCMYKLS_MCU_16s8u_P4C4R       ( const Fw16s *pSrcMCU[4],
                                                                    Fw8u  *pDstCMYK  , int dstStep );

FwStatus STDCALL fwiYCCK422ToCMYKLS_MCU_16s8u_P4C4R       ( const Fw16s *pSrcMCU[4],
                                                                    Fw8u  *pDstCMYK  , int dstStep );

FwStatus STDCALL fwiYCCK411ToCMYKLS_MCU_16s8u_P4C4R       ( const Fw16s *pSrcMCU[4],
                                                                    Fw8u  *pDstCMYK  , int dstStep );

////////////////////////////////////////////////////////////////
//                        QuantFwdRawTableInit_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantFwdRawTableInit_JPEG_8u          ( Fw8u *pQuantRawTable, int qualityFactor );

////////////////////////////////////////////////////////////////
//                        QuantFwdTableInit_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantFwdTableInit_JPEG_8u16u          ( const Fw8u  *pQuantRawTable, Fw16u *pQuantFwdTable );

////////////////////////////////////////////////////////////////
//                        QuantFwd8X8_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantFwd8x8_JPEG_16s_C1I              ( Fw16s *pSrcDst, const Fw16u *pQuantFwdTable );

////////////////////////////////////////////////////////////////
//                        QuantInvTableInit_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantInvTableInit_JPEG_8u16u          ( const Fw8u *pQuantRawTable, Fw16u *pQuantInvTable );

////////////////////////////////////////////////////////////////
//                        QuantInv8X8_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantInv8x8_JPEG_16s_C1I              ( Fw16s *pSrcDst, const Fw16u *pQuantInvTable );

////////////////////////////////////////////////////////////////
//                        DCTQuantFwd8X8_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDCTQuantFwd8x8_JPEG_16s_C1            ( const Fw16s *pSrc,
                                                                    Fw16s *pDst, const Fw16u *pQuantFwdTable );

FwStatus STDCALL fwiDCTQuantFwd8x8_JPEG_16s_C1I           (       Fw16s *pDst, const Fw16u *pQuantFwdTable );

////////////////////////////////////////////////////////////////
//                        DCTQuantFwd8X8LS_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDCTQuantFwd8x8LS_JPEG_8u16s_C1R       ( const Fw8u  *pSrc, int srcStep,
                                                                    Fw16s *pDst, const Fw16u *pQuantFwdTable );

////////////////////////////////////////////////////////////////
//                        DCTQuantInv8X8_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDCTQuantInv8x8_JPEG_16s_C1            ( const Fw16s *pSrc,
                                                                    Fw16s *pDst, const Fw16u *pQuantInvTable );

FwStatus STDCALL fwiDCTQuantInv8x8_JPEG_16s_C1I           (       Fw16s *pDst, const Fw16u *pQuantInvTable );

////////////////////////////////////////////////////////////////
//                        DCTQuantInv8X8LS_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDCTQuantInv8x8LS_JPEG_16s8u_C1R       ( const Fw16s *pSrc,
                                                                    Fw8u  *pDst, int dstStep, const Fw16u *pQuantInvTable );

////////////////////////////////////////////////////////////////
//                        Sub128_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiSub128_JPEG_8u16s_C1R                ( const Fw8u  *pSrc, int srcStep,
                                                                    Fw16s *pDst, int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        Add128_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwiAdd128_JPEG_16s8u_C1R                ( const Fw16s *pSrc, int srcStep,
                                                                    Fw8u  *pDst, int dstStep, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        SampleDownH2V1_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleDownH2V1_JPEG_8u_C1R            ( const Fw8u *pSrc, int srcStep, FwiSize srcSize,
                                                                    Fw8u *pDst, int dstStep, FwiSize dstSize );

////////////////////////////////////////////////////////////////
//                        SampleDownH2V2_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleDownH2V2_JPEG_8u_C1R            ( const Fw8u *pSrc, int srcStep, FwiSize srcSize,
                                                                    Fw8u *pDst, int dstStep, FwiSize dstSize );

////////////////////////////////////////////////////////////////
//                        SampleDownRowH2V1_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleDownRowH2V1_Box_JPEG_8u_C1      ( const Fw8u *pSrc,int srcWidth,
                                                                    Fw8u *pDst );

////////////////////////////////////////////////////////////////
//                        SampleDownRowH2V2_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleDownRowH2V2_Box_JPEG_8u_C1      ( const Fw8u *pSrc1, const Fw8u *pSrc2,int srcWidth,
                                                                    Fw8u *pDst );

////////////////////////////////////////////////////////////////
//                        SampleUpH2V1_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleUpH2V1_JPEG_8u_C1R              ( const Fw8u *pSrc, int srcStep, FwiSize srcSize,
                                                                    Fw8u *pDst, int dstStep, FwiSize dstSize );

////////////////////////////////////////////////////////////////
//                        SampleUpH2V2_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleUpH2V2_JPEG_8u_C1R              ( const Fw8u *pSrc, int srcStep, FwiSize srcSize,
                                                                    Fw8u *pDst, int dstStep, FwiSize dstSize );

////////////////////////////////////////////////////////////////
//                        SampleUpRowH2V1_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleUpRowH2V1_Triangle_JPEG_8u_C1   ( const Fw8u *pSrc, int srcWidth,
                                                                    Fw8u *pDst );

////////////////////////////////////////////////////////////////
//                        SampleUpRowH2V2_JPEG
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleUpRowH2V2_Triangle_JPEG_8u_C1   ( const Fw8u *pSrc1, const Fw8u *pSrc2, int srcWidth,
                                                                    Fw8u *pDst );

////////////////////////////////////////////////////////////////
//                        SampleDown4xxLS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleDown444LS_MCU_8u16s_C3P3R       ( const Fw8u  *pSrc, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL fwiSampleDown422LS_MCU_8u16s_C3P3R       ( const Fw8u  *pSrc, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

FwStatus STDCALL fwiSampleDown411LS_MCU_8u16s_C3P3R       ( const Fw8u  *pSrc, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        SampleUp4xxLS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSampleUp444LS_MCU_16s8u_P3C3R         ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDst      , int dstStep );

FwStatus STDCALL fwiSampleUp422LS_MCU_16s8u_P3C3R         ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDst      , int dstStep );

FwStatus STDCALL fwiSampleUp411LS_MCU_16s8u_P3C3R         ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDst      , int dstStep );

////////////////////////////////////////////////////////////////
//                        Split422LS_MCU
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwiSplit422LS_MCU_8u16s_C2P3R            ( const Fw8u  *pSrc, int srcStep,
                                                                    Fw16s *pDstMCU[3] );

////////////////////////////////////////////////////////////////
//                        Join422LS_MCU
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiJoin422LS_MCU_16s8u_P3C2R             ( const Fw16s *pSrcMCU[3],
                                                                    Fw8u  *pDst      , int dstStep );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanRawTableInit
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanRawTableInit_JPEG_8u     ( const int pStatistics[256],
                                                                    Fw8u *pListBits, Fw8u *pListVals );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanSpecGetBufSize
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanSpecGetBufSize_JPEG_8u   ( int *pSize );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanSpecInit
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanSpecInit_JPEG_8u         ( const Fw8u *pListBits,
                                                              const Fw8u *pListVals, FwiEncodeHuffmanSpec *pEncHuffSpec );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanSpecInitAlloc
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanSpecInitAlloc_JPEG_8u    ( const Fw8u *pListBits,
                                                              const Fw8u *pListVals, FwiEncodeHuffmanSpec* *pEncHuffSpec );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanSpecFree
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanSpecFree_JPEG_8u         ( FwiEncodeHuffmanSpec *pEncHuffSpec );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanStateGetBufSize
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanStateGetBufSize_JPEG_8u  ( int *pSize );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanStateInit
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanStateInit_JPEG_8u        ( FwiEncodeHuffmanState *pEncHuffState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanStateInitAlloc
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanStateInitAlloc_JPEG_8u   ( FwiEncodeHuffmanState* *pEncHuffState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffmanStateFree
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffmanStateFree_JPEG_8u        ( FwiEncodeHuffmanState *pEncHuffState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffman8X8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffman8x8_JPEG_16s1u_C1        ( const Fw16s *pSrc, Fw8u *pDst,
                                                              int dstLenBytes, int *pDstCurrPos, Fw16s *pLastDC,
                                                              const FwiEncodeHuffmanSpec *pDcTable,
                                                              const FwiEncodeHuffmanSpec *pAcTable, FwiEncodeHuffmanState *pEncHuffState, int bFlushState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffman8X8_Direct
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffman8x8_Direct_JPEG_16s1u_C1 ( const Fw16s *pSrc,
                                                                    Fw8u  *pDst, int *pDstBitsLen, Fw16s *pLastDC,
                                                              const FwiEncodeHuffmanSpec *pDcTable,
                                                              const FwiEncodeHuffmanSpec *pAcTable );

////////////////////////////////////////////////////////////////
//                        EncodeHuffman8X8_DCFirst
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffman8x8_DCFirst_JPEG_16s1u_C1( const Fw16s *pSrc,
                                                                    Fw8u  *pDst, int dstLenBytes, int *pDstCurrPos,
                                                                    Fw16s *pLastDC, int Al, const FwiEncodeHuffmanSpec *pDcTable, FwiEncodeHuffmanState *pEncHuffState, int bFlushState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffman8X8_DCRefine
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffman8x8_DCRefine_JPEG_16s1u_C1 ( const Fw16s *pSrc,
                                                                      Fw8u  *pDst, int dstLenBytes, int *pDstCurrPos, int Al,
                                                                FwiEncodeHuffmanState *pEncHuffState, int bFlushState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffman8X8_ACFirst
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffman8x8_ACFirst_JPEG_16s1u_C1( const Fw16s *pSrc,
                                                                    Fw8u  *pDst, int dstLenBytes, int *pDstCurrPos, int Ss,
                                                              int Se, int Al, const FwiEncodeHuffmanSpec  *pAcTable,
                                                                                    FwiEncodeHuffmanState *pEncHuffState, int bFlushState );

////////////////////////////////////////////////////////////////
//                        EncodeHuffman8X8_ACRefine
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEncodeHuffman8x8_ACRefine_JPEG_16s1u_C1 ( const Fw16s *pSrc,
                                                                      Fw8u  *pDst, int dstLenBytes, int *pDstCurrPos, int Ss,
                                                                int Se, int Al, const FwiEncodeHuffmanSpec  *pAcTable,
                                                                                      FwiEncodeHuffmanState *pEncHuffState, int bFlushState );

////////////////////////////////////////////////////////////////
//                        GetHuffmanStatistics8X8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetHuffmanStatistics8x8_JPEG_16s_C1   ( const Fw16s *pSrc,
                                                              int pDcStatistics[256], int pAcStatistics[256],
                                                                    Fw16s *pLastDC );

////////////////////////////////////////////////////////////////
//                        GetHuffmanStatistics8X8_DCFirst
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetHuffmanStatistics8x8_DCFirst_JPEG_16s_C1   ( const Fw16s *pSrc,
                                                                      int pDcStatistics[256], Fw16s *pLastDC, int Al );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanSpecGetBufSize
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanSpecGetBufSize_JPEG_8u ( int *pSize );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanSpecInit
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanSpecInit_JPEG_8u         ( const Fw8u *pListBits,
                                                              const Fw8u *pListVals, FwiDecodeHuffmanSpec *pDecHuffSpec );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanSpecInitAlloc
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanSpecInitAlloc_JPEG_8u    ( const Fw8u *pListBits,
                                                              const Fw8u *pListVals, FwiDecodeHuffmanSpec* *pDecHuffSpec );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanSpecFree
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanSpecFree_JPEG_8u         ( FwiDecodeHuffmanSpec *pDecHuffSpec );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanStateGetBufSize
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanStateGetBufSize_JPEG_8u  ( int *pSize );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanStateInit
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanStateInit_JPEG_8u        ( FwiDecodeHuffmanState *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanStateInitAlloc
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanStateInitAlloc_JPEG_8u   ( FwiDecodeHuffmanState* *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanStateFree
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanStateFree_JPEG_8u        ( FwiDecodeHuffmanState *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffman8X8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffman8x8_JPEG_1u16s_C1        ( const Fw8u *pSrc , int srcLenBytes  , int *pSrcCurrPos,
                                                                    Fw16s *pDst, Fw16s   *pLastDC, int *pMarker,
                                                              const FwiDecodeHuffmanSpec  *pDcTable, const FwiDecodeHuffmanSpec  *pAcTable, FwiDecodeHuffmanState *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffman8X8_Direct
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffman8x8_Direct_JPEG_1u16s_C1 ( const Fw8u  *pSrc, int *pSrcBitsLen,
                                                                    Fw16s *pDst, Fw16s  *pLastDC, int *pMarker, Fw32u *pPrefetchedBits, int *pNumValidPrefetchedBits,
                                                              const FwiDecodeHuffmanSpec *pDcTable, const FwiDecodeHuffmanSpec *pAcTable );

////////////////////////////////////////////////////////////////
//                        DecodeHuffman8X8_DCFirst
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffman8x8_DCFirst_JPEG_1u16s_C1( const Fw8u  *pSrc,int srcLenBytes , int *pSrcCurrPos,
                                                                    Fw16s *pDst, Fw16s *pLastDC, int *pMarker, int Al,
                                                              const FwiDecodeHuffmanSpec  *pDcTable, FwiDecodeHuffmanState *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffman8X8_DCRefine
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffman8x8_DCRefine_JPEG_1u16s_C1 ( const Fw8u *pSrc, int srcLenBytes, int *pSrcCurrPos,
                                                                      Fw16s *pDst, int *pMarker, int Al,
                                                                FwiDecodeHuffmanState *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffman8X8_ACFirst
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffman8x8_ACFirst_JPEG_1u16s_C1 ( const Fw8u  *pSrc, int srcLenBytes, int *pSrcCurrPos,
                                                                     Fw16s *pDst, int *pMarker, int Ss, int Se, int Al,
                                                               const FwiDecodeHuffmanSpec *pAcTable, FwiDecodeHuffmanState *pDecHuffState );

////////////////////////////////////////////////////////////////
//                        DecodeHuffman8X8_ACRefine
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffman8x8_ACRefine_JPEG_1u16s_C1 ( const Fw8u  *pSrc, int srcLenBytes, int *pSrcCurrPos,
                                                                      Fw16s *pDst, int *pMarker, int Ss, int Se, int Al,
                                                                const FwiDecodeHuffmanSpec *pAcTable, FwiDecodeHuffmanState *pDecHuffState );

#ifdef __cplusplus
}
#endif

#endif // __FWJPEG_H__
