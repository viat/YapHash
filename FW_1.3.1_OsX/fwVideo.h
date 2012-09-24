/*
Copyright (c) 2006-2009 Advanced Micro Devices, Inc. All Rights Reserved.
This software is subject to the Apache v2.0 License.
*/

#ifndef __FWVIDEO_H__
#define __FWVIDEO_H__

#include "fwBase.h"

//
// Enumerations
//
// H264-IntraPredict
enum {
    FW_UPPER        = 1  ,
    FW_LEFT         = 2  ,
    FW_CENTER       = 4  ,
    FW_RIGHT        = 8  ,
    FW_LOWER        = 16 ,
    FW_UPPER_LEFT   = 32 ,
    FW_UPPER_RIGHT  = 64 ,
    FW_LOWER_LEFT   = 128,
    FW_LOWER_RIGHT  = 256
};

// H264-MB Recon
typedef enum {
               FW_CHROMA_DC    = 0,
               FW_CHROMA_HOR   = 1,
               FW_CHROMA_VERT  = 2,
               FW_CHROMA_PLANE = 3
             } FwIntraChromaPredMode_H264;

typedef enum {
               FW_16X16_VERT   = 0,
               FW_16X16_HOR    = 1,
               FW_16X16_DC     = 2,
               FW_16X16_PLANE  = 3
             } FwIntra16x16PredMode_H264;

typedef enum {
               FW_4x4_VERT     = 0,
               FW_4x4_HOR      = 1,
               FW_4x4_DC       = 2,
               FW_4x4_DIAG_DL  = 3,
               FW_4x4_DIAG_DR  = 4,
               FW_4x4_VR       = 5,
               FW_4x4_HD       = 6,
               FW_4x4_VL       = 7,
               FW_4x4_HU       = 8
             } FwIntra4x4PredMode_H264;

#define        D_LEFT_EDGE      0x1
#define        D_RIGHT_EDGE     0x2
#define        D_TOP_EDGE       0x4
#define        D_BOTTOM_EDGE    0x8
#define        D_TOP_LEFT_EDGE  0x10
#define        D_TOP_RIGHT_EDGE 0x20

// H264-InterPredict
typedef enum _FWVC_FRAME_FIELD_FLAG
{
             FWVC_FRAME         = 0x0,
             FWVC_TOP_FIELD     = 0X1,
             FWVC_BOTTOM_FIELD  = 0x2
} FWVC_FRAME_FIELD_FLAG;

#define FwvcFrameFieldFlag FWVC_FRAME_FIELD_FLAG

//MPEG-2 Decoder
typedef Fw32s FwVCHuffmanSpec_32s;

#ifdef __cplusplus
extern "C" {
#endif


////////////////////////////////////////////////////////////////
//                        GetLibVersion
////////////////////////////////////////////////////////////////


const FwLibraryVersion* STDCALL fwvGetLibVersion ();

// ------------------------------------------------
//  H.264 decoder
// ------------------------------------------------

// ------------------------------------------------
//  H.264 CAVLC
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        DecodeCAVLCCoeffs_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeCAVLCCoeffs_H264_1u16s                (       Fw32u **ppBitStream, Fw32s *pBitOffset, Fw16s *pNumCoeff  ,
                                                                          Fw16s **ppDstCoeffs, Fw32u  uVLCSelect, Fw16s uMaxNumCoeff,
                                                                    const Fw32s **ppTblCoeffToken,
                                                                    const Fw32s **ppTblTotalZeros,
                                                                    const Fw32s **ppTblRunBefore ,
                                                                    const Fw32s  *pScanMatrix );

////////////////////////////////////////////////////////////////
//                        DecodeCAVLCChromaDcCoeffs_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeCAVLCChromaDcCoeffs_H264_1u16s        (       Fw32u **ppBitStream, Fw32s *pBitOffset  ,
                                                                          Fw16s  *pNumCoeff  , Fw16s **ppDstCoeffs,
                                                                    const Fw32s  *pTblCoeffToken   ,
                                                                    const Fw32s **ppTblTotalZerosCR, 
                                                                    const Fw32s **ppTblRunBefore );

////////////////////////////////////////////////////////////////
//                        DecodeExpGolombOne_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeExpGolombOne_H264_1u16s               ( Fw32u **ppBitStream, Fw32s *pBitOffset, Fw16s *pDst, Fw8u isSigned );

// ------------------------------------------------
//  H.264 Deblocking Filtering
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        FilterDeblockingLuma_VerEdge_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiFilterDeblockingLuma_VerEdge_H264_8u_C1IR   ( Fw8u *pSrcDst    , Fw32s srcDstStep,
                                                                    Fw8u *pAlpha     , Fw8u *pBeta     ,
                                                                    Fw8u *pThresholds, Fw8u *pBS );

////////////////////////////////////////////////////////////////
//                        FilterDeblockingLuma_HorEdge_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiFilterDeblockingLuma_HorEdge_H264_8u_C1IR   ( Fw8u *pSrcDst    , Fw32s srcDstStep,
                                                                    Fw8u *pAlpha     , Fw8u *pBeta     ,
                                                                    Fw8u *pThresholds, Fw8u *pBS );

////////////////////////////////////////////////////////////////
//                        FilterDeblockingChroma_HorEdge_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiFilterDeblockingChroma_HorEdge_H264_8u_C1IR ( Fw8u *pSrcDst    , Fw32s srcDstStep,
                                                                    Fw8u *pAlpha     , Fw8u *pBeta     ,
                                                                    Fw8u *pThresholds, Fw8u *pBS );

////////////////////////////////////////////////////////////////
//                        FilterDeblockingChroma_VerEdge_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiFilterDeblockingChroma_VerEdge_H264_8u_C1IR ( Fw8u *pSrcDst    , Fw32s srcDstStep,
                                                                    Fw8u *pAlpha     , Fw8u *pBeta     ,
                                                                    Fw8u *pThresholds, Fw8u *pBS );

// ------------------------------------------------
//  H.264 Inter-predict
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        InterpolateLuma_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiInterpolateLuma_H264_8u_C1R                 (const Fw8u *pSrc, Fw32s srcStep,
                                                                         Fw8u *pDst, Fw32s dstStep,
                                                                         Fw32s dx  , Fw32s dy, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        InterpolateLumaTop_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiInterpolateLumaTop_H264_8u_C1R              ( const Fw8u *pSrc, Fw32s srcStep,
                                                                          Fw8u *pDst, Fw32s dstStep,
                                                                          Fw32s dx  , Fw32s dy, Fw32s outPixels, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        InterpolateLumaBottom_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiInterpolateLumaBottom_H264_8u_C1R           ( const Fw8u *pSrc, Fw32s srcStep, 
                                                                          Fw8u *pDst, Fw32s dstStep,
                                                                          Fw32s dx  , Fw32s dy, Fw32s outPixels, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        InterpolateChroma_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiInterpolateChroma_H264_8u_C1R               ( const Fw8u *pSrc, Fw32s srcStep,
                                                                          Fw8u *pDst, Fw32s dstStep,
                                                                          Fw32s dx  , Fw32s dy, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        InterpolateChromaTop_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiInterpolateChromaTop_H264_8u_C1R            ( const Fw8u *pSrc, Fw32s srcStep,
                                                                          Fw8u *pDst, Fw32s dstStep,
                                                                          Fw32s dx  , Fw32s dy, Fw32s outPixels, FwiSize roiSize );

////////////////////////////////////////////////////////////////
//                        InterpolateChromaBottom_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiInterpolateChromaBottom_H264_8u_C1R         ( const Fw8u *pSrc, Fw32s srcStep,
                                                                          Fw8u *pDst, Fw32s dstStep,
                                                                          Fw32s dx  , Fw32s dy, Fw32s outPixels, FwiSize roiSize );



// ------------------------------------------------
//  H.264 Intra-predict
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        PredictIntra_4x4_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiPredictIntra_4x4_H264_8u_C1IR               ( Fw8u *pSrcDst, Fw32s srcDstStep,
                                                                    FwIntra4x4PredMode_H264 predMode, Fw32s availability );

////////////////////////////////////////////////////////////////
//                        PredictIntra_16x16_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiPredictIntra_16x16_H264_8u_C1IR             ( Fw8u *pSrcDst, Fw32s srcDstStep  ,
                                                                    FwIntra16x16PredMode_H264 predMode, Fw32s availability );

////////////////////////////////////////////////////////////////
//                        PredictIntraChroma8x8_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiPredictIntraChroma8x8_H264_8u_C1IR          ( Fw8u *pSrcDst, Fw32s srcDstStep   ,
                                                                    FwIntraChromaPredMode_H264 predMode, Fw32s availability );

// ------------------------------------------------
//  H.264 Reconstruction
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        ReconstructChromaInterMB_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiReconstructChromaInterMB_H264_16s8u_P2R     (       Fw16s **ppSrcCoeff  ,       Fw8u  *pSrcDstUPlane,
                                                                          Fw8u  *pSrcDstVPlane, const Fw32u srcDstStep    ,
                                                                    const Fw32u cbp4x4        , const Fw32s ChromaQP );

////////////////////////////////////////////////////////////////
//                        ReconstructChromaIntraMB_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiReconstructChromaIntraMB_H264_16s8u_P2R     ( Fw16s **ppSrcCoeff   ,       Fw8u *pSrcDstUPlane,
                                                                    Fw8u  *pSrcDstVPlane , const Fw32u srcDstUVStep ,
                                                                    const FwIntraChromaPredMode_H264 intraChromaMode ,
                                                                    const Fw32u cbp4x4   , const Fw32u ChromaQP     ,
                                                                    const Fw8u edgeType );

////////////////////////////////////////////////////////////////
//                        ReconstructLumaInterMB_H264
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwiReconstructLumaInterMB_H264_16s8u_C1R       (       Fw16s **ppSrcCoeff, Fw8u *pSrcDstYPlane,
                                                                    const Fw32u srcDstYStep ,
                                                                    const Fw32u cbp4x4      ,
                                                                    const Fw32s QP );

////////////////////////////////////////////////////////////////
//                        ReconstructLumaIntraMB_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiReconstructLumaIntraMB_H264_16s8u_C1R       (       Fw16s **ppSrcCoeff, Fw8u *pSrcDstYPlane,
                                                                          Fw32s srcDstYStep ,
                                                                    const FwIntra4x4PredMode_H264 *pMBIntraTypes  ,
                                                                    const Fw32u cbp4x4      ,
                                                                    const Fw32u QP          ,
                                                                    const Fw8u edgeType );

// ------------------------------------------------
// H.264 Inverse Transform
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        TransformDequantChromaDC_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiTransformDequantChromaDC_H264_16s_C1I       ( Fw16s *pSrcDst, Fw32s QP );

////////////////////////////////////////////////////////////////
//                        DequantTransformResidual_H264
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDequantTransformResidual_H264_16s_C1I       ( Fw16s *pSrcDst, Fw32s step, Fw16s *pDC, Fw32s AC, Fw32s QP );

////////////////////////////////////////////////////////////////
//                        HuffmanTableInitAlloc
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiHuffmanTableInitAlloc_32s                   ( const Fw32s *pSrcTable, FwVCHuffmanSpec_32s **ppDstSpec );

////////////////////////////////////////////////////////////////
//                        HuffmanRunLevelTableInitAlloc
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiHuffmanRunLevelTableInitAlloc_32s           ( const Fw32s *pSrcTable, FwVCHuffmanSpec_32s **ppDstSpec );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanOne
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanOne_1u32s                      ( Fw32u **ppBitStream, Fw32s *pOffset, Fw32s *pDst, const FwVCHuffmanSpec_32s *pDecodeTable );

////////////////////////////////////////////////////////////////
//                        DecodeHuffmanPair
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDecodeHuffmanPair_1u16s                     ( Fw32u **ppBitStream, Fw32s *pOffset, const FwVCHuffmanSpec_32s *pDecodeTable, Fw8s *pFirst, Fw16s *pSecond );

////////////////////////////////////////////////////////////////
//                        HuffmanTableFree
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiHuffmanTableFree_32s                        ( FwVCHuffmanSpec_32s **ppDecodeTable );
// ------------------------------------------------
//  Motion Compensation
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        MC16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x16_8u_C1         ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x8_8u_C1          ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC8x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC8x16_8u_C1          ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC8x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC8x8_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC8x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC8x4_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC4x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC4x8_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC4x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC4x4_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC2x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC2x4_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC4x2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC4x2_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC2x2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC2x2_8u_C1           ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x4_8u_C1          ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x8UV
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x8UV_8u_C1        ( const Fw8u  *pSrcRef  , Fw32s srcStep     ,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep,
                                                    Fw8u  *pDst     , Fw32s dstStep     ,
                                                    Fw32s  mcType   , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x16B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x16B_8u_C1        ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x8B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x8B_8u_C1         ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC8x16B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC8x16B_8u_C1         ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u *pDst   ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC8x8B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC8x8B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u *pDst   ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC8x4B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC8x4B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u *pDst   ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC4x8B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC4x8B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u *pDst   ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC4x4B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC4x4B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC2x4B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC2x4B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC4x2B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC4x2B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC2x2B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC2x2B_8u_C1          ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x4B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x4B_8u_C1         ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        MC16x8BUV
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiMC16x8BUV_8u_C1       ( const Fw8u  *pSrcRefF , Fw32s srcStepF    , Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB , Fw32s srcStepB    , Fw32s mcTypeB,
                                              const Fw16s *pSrcYData, Fw32s srcYDataStep, Fw8u  *pDst  ,
                                                    Fw32s  dstStep  , Fw32s roundControl );

// ------------------------------------------------
//  Motion Estimation
// ------------------------------------------------


////////////////////////////////////////////////////////////////
//                        GetDiff16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff16x16_8u16s_C1 ( const Fw8u  *pSrcCur      , Fw32s srcCurStep      ,
                                              const Fw8u  *pSrcRef      , Fw32s srcRefStep      ,
                                                    Fw16s *pDstDiff     , Fw32s dstDiffStep     ,
                                                    Fw16s *pDstPredictor, Fw32s dstPredictorStep,
                                                    Fw32s  mcType       , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff16x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff16x8_8u16s_C1  ( const Fw8u  *pSrcCur      , Fw32s srcCurStep      ,
                                              const Fw8u  *pSrcRef      , Fw32s srcRefStep      ,
                                                    Fw16s *pDstDiff     , Fw32s dstDiffStep     ,
                                                    Fw16s *pDstPredictor, Fw32s dstPredictorStep,
                                                    Fw32s  mcType       , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff8x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff8x8_8u16s_C1   ( const Fw8u  *pSrcCur      , Fw32s srcCurStep      ,
                                              const Fw8u  *pSrcRef      , Fw32s srcRefStep      ,
                                                    Fw16s *pDstDiff     , Fw32s dstDiffStep     ,
                                                    Fw16s *pDstPredictor, Fw32s dstPredictorStep,
                                                    Fw32s  mcType       , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff8x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff8x16_8u16s_C1  ( const Fw8u  *pSrcCur      , Fw32s srcCurStep      ,
                                              const Fw8u  *pSrcRef      , Fw32s srcRefStep      ,
                                                    Fw16s *pDstDiff     , Fw32s dstDiffStep     ,
                                                    Fw16s *pDstPredictor, Fw32s dstPredictorStep,
                                                    Fw32s  mcType       , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff8x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff8x4_8u16s_C1   ( const Fw8u  *pSrcCur      , Fw32s srcCurStep      ,
                                              const Fw8u  *pSrcRef      , Fw32s srcRefStep      ,
                                                    Fw16s *pDstDiff     , Fw32s dstDiffStep     ,
                                                    Fw16s *pDstPredictor, Fw32s dstPredictorStep,
                                                    Fw32s  mcType       , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff4x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff4x4_8u16s_C1   ( const Fw8u  *pSrcCur      , Fw32s srcCurStep      ,
                                              const Fw8u  *pSrcRef      , Fw32s srcRefStep      ,
                                                    Fw16s *pDstDiff     , Fw32s dstDiffStep     ,
                                                    Fw16s *pDstPredictor, Fw32s dstPredictorStep,
                                                    Fw32s  mcType       , Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff16x16B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff16x16B_8u16s_C1 ( const Fw8u  *pSrcCur , Fw32s srcCurStep ,
                                               const Fw8u  *pSrcRefF, Fw32s srcRefStepF, Fw32s mcTypeF,
                                               const Fw8u  *pSrcRefB, Fw32s srcRefStepB, Fw32s mcTypeB, 
                                                     Fw16s *pDstDiff, Fw32s dstDiffStep, Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff16x8B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff16x8B_8u16s_C1 ( const Fw8u  *pSrcCur , Fw32s srcCurStep ,
                                              const Fw8u  *pSrcRefF, Fw32s srcRefStepF, Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB, Fw32s srcRefStepB, Fw32s mcTypeB, 
                                                    Fw16s *pDstDiff, Fw32s dstDiffStep, Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff8x8B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff8x8B_8u16s_C1  ( const Fw8u  *pSrcCur , Fw32s srcCurStep ,
                                              const Fw8u  *pSrcRefF, Fw32s srcRefStepF, Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB, Fw32s srcRefStepB, Fw32s mcTypeB, 
                                                    Fw16s *pDstDiff, Fw32s dstDiffStep, Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff8x16B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff8x16B_8u16s_C1 ( const Fw8u  *pSrcCur , Fw32s srcCurStep ,
                                              const Fw8u  *pSrcRefF, Fw32s srcRefStepF, Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB, Fw32s srcRefStepB, Fw32s mcTypeB,
                                                    Fw16s *pDstDiff, Fw32s dstDiffStep, Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        GetDiff8x4B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiGetDiff8x4B_8u16s_C1  ( const Fw8u  *pSrcCur , Fw32s srcCurStep ,
                                              const Fw8u  *pSrcRefF, Fw32s srcRefStepF, Fw32s mcTypeF,
                                              const Fw8u  *pSrcRefB, Fw32s srcRefStepB, Fw32s mcTypeB,
                                                    Fw16s *pDstDiff, Fw32s dstDiffStep, Fw32s roundControl );

////////////////////////////////////////////////////////////////
//                        SqrDiff16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSqrDiff16x16_8u32s    ( const Fw8u *pSrc  , Fw32s srcStep,
                                              const Fw8u *pRef  , Fw32s refStep,
                                                    Fw32s mcType, Fw32s *pSqrDiff );

////////////////////////////////////////////////////////////////
//                        SqrDiff16x16B
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSqrDiff16x16B_8u32s   ( const Fw8u  *pSrc , Fw32s srcStep ,
                                              const Fw8u  *pRefF, Fw32s refStepF, Fw32s mcTypeF,
                                              const Fw8u  *pRefB, Fw32s refStepB, Fw32s mcTypeB,
                                                    Fw32s *pSqrDiff );

////////////////////////////////////////////////////////////////
//                        VarMean8x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiVarMean8x8_8u32s_C1R  ( const Fw8u  *pSrc, Fw32s srcStep, Fw32s *pVar, Fw32s *pMean );
FwStatus STDCALL fwiVarMean8x8_16s32s_C1R ( const Fw16s *pSrc, Fw32s srcStep, Fw32s *pVar, Fw32s *pMean );

////////////////////////////////////////////////////////////////
//                        VarMeanDiff16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiVarMeanDiff16x16_8u32s_C1R      ( const Fw8u  *pSrc , Fw32s srcStep,
                                                        const Fw8u  *pRef , Fw32s refStep, Fw32s *pSrcSum,
                                                              Fw32s *pVar , Fw32s *pMean , Fw32s  mcType );

////////////////////////////////////////////////////////////////
//                        VarMeanDiff16x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiVarMeanDiff16x8_8u32s_C1R       ( const Fw8u  *pSrc , Fw32s srcStep,
                                                        const Fw8u  *pRef , Fw32s refStep, Fw32s *pSrcSum,
                                                              Fw32s *pVar , Fw32s *pMean , Fw32s  mcType );

////////////////////////////////////////////////////////////////
//                        Variance16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiVariance16x16_8u32s             ( const Fw8u *pSrc, Fw32s srcStep, Fw32s *pVar );

////////////////////////////////////////////////////////////////
//                        EdgesDetect16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiEdgesDetect16x16_8u_C1R         ( const Fw8u *pSrc, Fw32u srcStep, Fw8u EdgePelDifference, Fw8u EdgePelCount, Fw8u *pRes );

////////////////////////////////////////////////////////////////
//                        SAD16x16
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSAD16x16_8u32s                  ( const Fw8u  *pSrc, Fw32s srcStep,
                                                        const Fw8u  *pRef, Fw32s refStep,
                                                              Fw32s *pSAD, Fw32s mcType );

////////////////////////////////////////////////////////////////
//                        SAD8x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSAD8x8_8u32s_C1R                ( const Fw8u  *pSrcCur, int srcCurStep, 
                                                        const Fw8u  *pSrcRef, Fw32s srcRefStep,
                                                              Fw32s *pDst   , Fw32s mcType );

////////////////////////////////////////////////////////////////
//                        SAD4x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSAD4x4_8u32s                    ( const Fw8u  *pSrc, Fw32s srcStep,
                                                              Fw8u  *pRef, Fw32s refStep, 
                                                              Fw32s *pSAD, Fw32s mcType );

////////////////////////////////////////////////////////////////
//                        SAD16x16Blocks8x8
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSAD16x16Blocks8x8_8u16u         ( const Fw8u  *pSrc   , Fw32s srcStep, 
                                                              Fw8u  *pRef   , Fw32s refStep, 
                                                              Fw16u *pDstSAD, Fw32s mcType );

////////////////////////////////////////////////////////////////
//                        SAD16x16Blocks4x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSAD16x16Blocks4x4_8u16u         ( const Fw8u  *pSrc   , Fw32s srcStep,
                                                              Fw8u  *pRef   , Fw32s refStep,
                                                              Fw16u *pDstSAD, Fw32s mcType );

////////////////////////////////////////////////////////////////
//                        SumsDiff16x16Blocks4x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSumsDiff16x16Blocks4x4_8u16s_C1 ( Fw8u  *pSrc , Fw32s srcStep ,
                                                        Fw8u  *pPred, Fw32s predStep,
                                                        Fw16s *pSums, Fw16s *pDiff );

////////////////////////////////////////////////////////////////
//                        SumsDiff8x8Blocks4x4
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiSumsDiff8x8Blocks4x4_8u16s_C1   ( Fw8u  *pSrc , Fw32s srcStep ,
                                                        Fw8u  *pPred, Fw32s predStep,
                                                        Fw16s *pSums, Fw16s *pDiff );

////////////////////////////////////////////////////////////////
//                        QuantInv_MPEG2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantInv_MPEG2_16s_C1I                        ( Fw16s *pSrcDst, int QP, Fw16s *pQPMatrix );

////////////////////////////////////////////////////////////////
//                        QuantInvIntra_MPEG2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiQuantInvIntra_MPEG2_16s_C1I                   ( Fw16s *pSrcDst, int QP, Fw16s *pQPMatrix );

////////////////////////////////////////////////////////////////
//                        ReconstructDCTBlock_MPEG1
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiReconstructDCTBlock_MPEG1_32s                 (      Fw32u **ppBitStream, int *pOffset,
                                                                     const Fw32s *pDCSizeTable,
                                                                     const Fw32s *pACTable    ,
                                                                           Fw32s *pScanMatrix , int QP, Fw16s *pQPMatrix,
                                                                           Fw16s *pDstBlock   ,         Fw32s *pDstSize );

////////////////////////////////////////////////////////////////
//                        ReconstructDCTBlockIntra_MPEG1
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwiReconstructDCTBlockIntra_MPEG1_32s            (      Fw32u **ppBitStream, int *pOffset,
                                                                     const Fw32s *pDCSizeTable,
                                                                     const Fw32s *pACTable    ,
                                                                           Fw32s *pScanMatrix , int QP, Fw16s *pQPMatrix,
                                                                           Fw16s *pDCPred     ,         Fw16s *pDstBlock, Fw32s *pDstSize );

////////////////////////////////////////////////////////////////
//                        ReconstructDCTBlock_MPEG2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiReconstructDCTBlock_MPEG2_32s                 (       Fw32u **ppBitStream, int *pOffset,
                                                                      const FwVCHuffmanSpec_32s *pDCTable,
                                                                      const FwVCHuffmanSpec_32s *pACTable,
                                                                            Fw32s *pScanMatrix , int QP, Fw16s *pQPMatrix,
                                                                            Fw16s *pDstBlock   , Fw32s *pDstSize );

////////////////////////////////////////////////////////////////
//                        ReconstructDCTBlockIntra_MPEG2
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwiReconstructDCTBlockIntra_MPEG2_32s            (       Fw32u **ppBitStream, int *pOffset,
                                                                      const FwVCHuffmanSpec_32s *pDCSizeTable,
                                                                      const FwVCHuffmanSpec_32s *pACTable    ,
                                                                            Fw32s *pScanMatrix , int QP, Fw16s *pQPMatrix, 
                                                                            Fw16s *pDCPred     , Fw32s shiftDCVal, 
                                                                            Fw16s *pDstBlock   , Fw32s *pDstSize );

////////////////////////////////////////////////////////////////
//                        DCT8x8Inv_AANTransposed_Channel
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDCT8x8Inv_AANTransposed_16s_C1R               ( const Fw16s *pSrc, Fw16s *pDst, Fw32s dstStep, Fw32s count );
FwStatus STDCALL fwiDCT8x8Inv_AANTransposed_16s8u_C1R             ( const Fw16s *pSrc, Fw8u  *pDst, Fw32s dstStep, Fw32s count );

////////////////////////////////////////////////////////////////
//                        DCT8x8Inv_AANTransposed_Plane
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwiDCT8x8Inv_AANTransposed_16s_P2C2R             ( const Fw16s *pSrcU, const Fw16s *pSrcV, Fw16s *pDstUV, Fw32s dstStep, Fw32s countU, Fw32s countV );
FwStatus STDCALL fwiDCT8x8Inv_AANTransposed_16s8u_P2C2R           ( const Fw16s *pSrcU, const Fw16s *pSrcV, Fw8u  *pDstUV, Fw32s dstStep, Fw32s countU, Fw32s countV );

#ifdef __cplusplus
}
#endif


#endif // __FWVIDEO_H__
