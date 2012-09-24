/*
Copyright (c) 2006-2009 Advanced Micro Devices, Inc. All Rights Reserved.
This software is subject to the Apache v2.0 License.
*/

#ifndef __FWSIGNAL_H__
#define __FWSIGNAL_H__

#include "fwBase.h"


#ifdef __cplusplus
extern "C" {
#endif


////////////////////////////////////////////////////////////////
//                        GetLibVersion
////////////////////////////////////////////////////////////////

const FwLibraryVersion* STDCALL fwsGetLibVersion ();

////////////////////////////////////////////////////////////////
//                        Add
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAdd_8u16u             ( const Fw8u   *pSrc1, const Fw8u   *pSrc2  , Fw16u  *pDst, int len );
FwStatus STDCALL fwsAdd_32u               ( const Fw32u  *pSrc1, const Fw32u  *pSrc2  , Fw32u  *pDst, int len );
FwStatus STDCALL fwsAdd_32f               ( const Fw32f  *pSrc1, const Fw32f  *pSrc2  , Fw32f  *pDst, int len );
FwStatus STDCALL fwsAdd_64s		         (const Fw64s* pSrc1, const Fw64s* pSrc2, Fw64s* pDst, int len);
FwStatus STDCALL fwsAdd_64f               ( const Fw64f  *pSrc1, const Fw64f  *pSrc2  , Fw64f  *pDst, int len );
FwStatus STDCALL fwsAdd_32fc              ( const Fw32fc *pSrc1, const Fw32fc *pSrc2  , Fw32fc *pDst, int len );
FwStatus STDCALL fwsAdd_64fc              ( const Fw64fc *pSrc1, const Fw64fc *pSrc2  , Fw64fc *pDst, int len );
FwStatus STDCALL fwsAdd_16s32f            ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw32f  *pDst, int len );

FwStatus STDCALL fwsAdd_16s_I             ( const Fw16s  *pSrc ,       Fw16s  *pSrcDst,                int len );
FwStatus STDCALL fwsAdd_16s32s_I          ( const Fw16s  *pSrc ,       Fw32s  *pSrcDst,                int len );
FwStatus STDCALL fwsAdd_32f_I             ( const Fw32f  *pSrc ,       Fw32f  *pSrcDst,                int len );
FwStatus STDCALL fwsAdd_64f_I             ( const Fw64f  *pSrc ,       Fw64f  *pSrcDst,                int len );
FwStatus STDCALL fwsAdd_32fc_I            ( const Fw32fc *pSrc ,       Fw32fc *pSrcDst,                int len );
FwStatus STDCALL fwsAdd_64fc_I            ( const Fw64fc *pSrc ,       Fw64fc *pSrcDst,                int len );

FwStatus STDCALL fwsAdd_8u_Sfs            ( const Fw8u   *pSrc1, const Fw8u   *pSrc2  , Fw8u   *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsAdd_16s_Sfs           ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsAdd_32s_Sfs           ( const Fw32s  *pSrc1, const Fw32s  *pSrc2  , Fw32s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsAdd_16sc_Sfs          ( const Fw16sc *pSrc1, const Fw16sc *pSrc2  , Fw16sc *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsAdd_32sc_Sfs          ( const Fw32sc *pSrc1, const Fw32sc *pSrc2  , Fw32sc *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsAdd_8u_ISfs           ( const Fw8u   *pSrc ,       Fw8u   *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsAdd_16s_ISfs          ( const Fw16s  *pSrc ,       Fw16s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsAdd_32s_ISfs          ( const Fw32s  *pSrc ,       Fw32s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsAdd_16sc_ISfs         ( const Fw16sc *pSrc ,       Fw16sc *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsAdd_32sc_ISfs         ( const Fw32sc *pSrc ,       Fw32sc *pSrcDst,                int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        AddC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAddC_32f              ( const Fw32f  *pSrc, Fw32f  val, Fw32f  *pDst   , int len );
FwStatus STDCALL fwsAddC_64f              ( const Fw64f  *pSrc, Fw64f  val, Fw64f  *pDst   , int len );
FwStatus STDCALL fwsAddC_32fc             ( const Fw32fc *pSrc, Fw32fc val, Fw32fc *pDst   , int len );
FwStatus STDCALL fwsAddC_64fc             ( const Fw64fc *pSrc, Fw64fc val, Fw64fc *pDst   , int len );

FwStatus STDCALL fwsAddC_16s_I            (                      Fw16s  val, Fw16s  *pSrcDst, int len );
FwStatus STDCALL fwsAddC_32f_I            (                      Fw32f  val, Fw32f  *pSrcDst, int len );
FwStatus STDCALL fwsAddC_64f_I            (                      Fw64f  val, Fw64f  *pSrcDst, int len );
FwStatus STDCALL fwsAddC_32fc_I           (                      Fw32fc val, Fw32fc *pSrcDst, int len );
FwStatus STDCALL fwsAddC_64fc_I           (                      Fw64fc val, Fw64fc *pSrcDst, int len );

FwStatus STDCALL fwsAddC_8u_Sfs           ( const Fw8u   *pSrc, Fw8u   val, Fw8u   *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsAddC_16s_Sfs          ( const Fw16s  *pSrc, Fw16s  val, Fw16s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsAddC_32s_Sfs          ( const Fw32s  *pSrc, Fw32s  val, Fw32s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsAddC_16sc_Sfs         ( const Fw16sc *pSrc, Fw16sc val, Fw16sc *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsAddC_32sc_Sfs         ( const Fw32sc *pSrc, Fw32sc val, Fw32sc *pDst   , int len, int scaleFactor );

FwStatus STDCALL fwsAddC_8u_ISfs          (                      Fw8u   val, Fw8u   *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsAddC_16s_ISfs         (                      Fw16s  val, Fw16s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsAddC_32s_ISfs         (                      Fw32s  val, Fw32s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsAddC_16sc_ISfs        (                      Fw16sc val, Fw16sc *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsAddC_32sc_ISfs        (                      Fw32sc val, Fw32sc *pSrcDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Sub
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSub_16s               ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len );
FwStatus STDCALL fwsSub_32f               ( const Fw32f  *pSrc1, const Fw32f  *pSrc2  , Fw32f  *pDst, int len );
FwStatus STDCALL fwsSub_64f               ( const Fw64f  *pSrc1, const Fw64f  *pSrc2  , Fw64f  *pDst, int len );
FwStatus STDCALL fwsSub_64s               ( const Fw64s  *pSrc1, const Fw64s  *pSrc2  , Fw64s  *pDst, int len );
FwStatus STDCALL fwsSub_32fc              ( const Fw32fc *pSrc1, const Fw32fc *pSrc2  , Fw32fc *pDst, int len );
FwStatus STDCALL fwsSub_64fc              ( const Fw64fc *pSrc1, const Fw64fc *pSrc2  , Fw64fc *pDst, int len );
FwStatus STDCALL fwsSub_16s32f            ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw32f  *pDst, int len );

FwStatus STDCALL fwsSub_16s_I             ( const Fw16s  *pSrc ,       Fw16s  *pSrcDst,                int len );
FwStatus STDCALL fwsSub_32f_I             ( const Fw32f  *pSrc ,       Fw32f  *pSrcDst,                int len );
FwStatus STDCALL fwsSub_64f_I             ( const Fw64f  *pSrc ,       Fw64f  *pSrcDst,                int len );
FwStatus STDCALL fwsSub_32fc_I            ( const Fw32fc *pSrc ,       Fw32fc *pSrcDst,                int len );
FwStatus STDCALL fwsSub_64fc_I            ( const Fw64fc *pSrc ,       Fw64fc *pSrcDst,                int len );

FwStatus STDCALL fwsSub_8u_Sfs            ( const Fw8u   *pSrc1, const Fw8u   *pSrc2  , Fw8u   *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSub_16s_Sfs           ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSub_32s_Sfs           ( const Fw32s  *pSrc1, const Fw32s  *pSrc2  , Fw32s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSub_16sc_Sfs          ( const Fw16sc *pSrc1, const Fw16sc *pSrc2  , Fw16sc *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSub_32sc_Sfs          ( const Fw32sc *pSrc1, const Fw32sc *pSrc2  , Fw32sc *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsSub_8u_ISfs           ( const Fw8u   *pSrc ,       Fw8u   *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSub_16s_ISfs          ( const Fw16s  *pSrc ,       Fw16s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSub_32s_ISfs          ( const Fw32s  *pSrc ,       Fw32s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSub_16sc_ISfs         ( const Fw16sc *pSrc ,       Fw16sc *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSub_32sc_ISfs         ( const Fw32sc *pSrc ,       Fw32sc *pSrcDst,                int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        SubC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSubC_32f              ( const Fw32f  *pSrc, Fw32f  val, Fw32f  *pDst   , int len );
FwStatus STDCALL fwsSubC_64f              ( const Fw64f  *pSrc, Fw64f  val, Fw64f  *pDst   , int len );
FwStatus STDCALL fwsSubC_32fc             ( const Fw32fc *pSrc, Fw32fc val, Fw32fc *pDst   , int len );
FwStatus STDCALL fwsSubC_64fc             ( const Fw64fc *pSrc, Fw64fc val, Fw64fc *pDst   , int len );

FwStatus STDCALL fwsSubC_16s_I            (                      Fw16s  val, Fw16s  *pSrcDst, int len );
FwStatus STDCALL fwsSubC_32f_I            (                      Fw32f  val, Fw32f  *pSrcDst, int len );
FwStatus STDCALL fwsSubC_64f_I            (                      Fw64f  val, Fw64f  *pSrcDst, int len );
FwStatus STDCALL fwsSubC_32fc_I           (                      Fw32fc val, Fw32fc *pSrcDst, int len );
FwStatus STDCALL fwsSubC_64fc_I           (                      Fw64fc val, Fw64fc *pSrcDst, int len );

FwStatus STDCALL fwsSubC_8u_Sfs           ( const Fw8u   *pSrc, Fw8u   val, Fw8u   *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubC_16s_Sfs          ( const Fw16s  *pSrc, Fw16s  val, Fw16s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubC_32s_Sfs          ( const Fw32s  *pSrc, Fw32s  val, Fw32s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubC_16sc_Sfs         ( const Fw16sc *pSrc, Fw16sc val, Fw16sc *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubC_32sc_Sfs         ( const Fw32sc *pSrc, Fw32sc val, Fw32sc *pDst   , int len, int scaleFactor );

FwStatus STDCALL fwsSubC_8u_ISfs          (                      Fw8u   val, Fw8u   *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubC_16s_ISfs         (                      Fw16s  val, Fw16s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubC_32s_ISfs         (                      Fw32s  val, Fw32s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubC_16sc_ISfs        (                      Fw16sc val, Fw16sc *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubC_32sc_ISfs        (                      Fw32sc val, Fw32sc *pSrcDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        SubCRev
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSubCRev_32f           ( const Fw32f  *pSrc, Fw32f  val, Fw32f  *pDst   , int len );
FwStatus STDCALL fwsSubCRev_64f           ( const Fw64f  *pSrc, Fw64f  val, Fw64f  *pDst   , int len );
FwStatus STDCALL fwsSubCRev_32fc          ( const Fw32fc *pSrc, Fw32fc val, Fw32fc *pDst   , int len );
FwStatus STDCALL fwsSubCRev_64fc          ( const Fw64fc *pSrc, Fw64fc val, Fw64fc *pDst   , int len );

FwStatus STDCALL fwsSubCRev_32f_I         (                      Fw32f  val, Fw32f  *pSrcDst, int len );
FwStatus STDCALL fwsSubCRev_64f_I         (                      Fw64f  val, Fw64f  *pSrcDst, int len );
FwStatus STDCALL fwsSubCRev_32fc_I        (                      Fw32fc val, Fw32fc *pSrcDst, int len );
FwStatus STDCALL fwsSubCRev_64fc_I        (                      Fw64fc val, Fw64fc *pSrcDst, int len );

FwStatus STDCALL fwsSubCRev_8u_Sfs        ( const Fw8u   *pSrc, Fw8u   val, Fw8u   *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_16s_Sfs       ( const Fw16s  *pSrc, Fw16s  val, Fw16s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_32s_Sfs       ( const Fw32s  *pSrc, Fw32s  val, Fw32s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_16sc_Sfs      ( const Fw16sc *pSrc, Fw16sc val, Fw16sc *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_32sc_Sfs      ( const Fw32sc *pSrc, Fw32sc val, Fw32sc *pDst   , int len, int scaleFactor );

FwStatus STDCALL fwsSubCRev_8u_ISfs       (                      Fw8u   val, Fw8u   *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_16s_ISfs      (                      Fw16s  val, Fw16s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_32s_ISfs      (                      Fw32s  val, Fw32s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_16sc_ISfs     (                      Fw16sc val, Fw16sc *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsSubCRev_32sc_ISfs     (                      Fw32sc val, Fw32sc *pSrcDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        AddProduct
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAddProduct_32f        ( const Fw32f  *pSrc1, const Fw32f  *pSrc2, Fw32f  *pSrcDst, int len );
FwStatus STDCALL fwsAddProduct_64f        ( const Fw64f  *pSrc1, const Fw64f  *pSrc2, Fw64f  *pSrcDst, int len );
FwStatus STDCALL fwsAddProduct_32fc       ( const Fw32fc *pSrc1, const Fw32fc *pSrc2, Fw32fc *pSrcDst, int len );
FwStatus STDCALL fwsAddProduct_64fc       ( const Fw64fc *pSrc1, const Fw64fc *pSrc2, Fw64fc *pSrcDst, int len );

FwStatus STDCALL fwsAddProduct_16s_Sfs    ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, Fw16s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsAddProduct_32s_Sfs    ( const Fw32s  *pSrc1, const Fw32s  *pSrc2, Fw32s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsAddProduct_16s32s_Sfs ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, Fw32s  *pSrcDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        And
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAnd_8u                ( const Fw8u  *pSrc1, const Fw8u  *pSrc2  , Fw8u  *pDst, int len );
FwStatus STDCALL fwsAnd_16u               ( const Fw16u *pSrc1, const Fw16u *pSrc2  , Fw16u *pDst, int len );
FwStatus STDCALL fwsAnd_32u               ( const Fw32u *pSrc1, const Fw32u *pSrc2  , Fw32u *pDst, int len );

FwStatus STDCALL fwsAnd_8u_I              ( const Fw8u  *pSrc ,       Fw8u  *pSrcDst,               int len );
FwStatus STDCALL fwsAnd_16u_I             ( const Fw16u *pSrc ,       Fw16u *pSrcDst,               int len );
FwStatus STDCALL fwsAnd_32u_I             ( const Fw32u *pSrc ,       Fw32u *pSrcDst,               int len );

////////////////////////////////////////////////////////////////
//                        Or
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsOr_8u                 ( const Fw8u  *pSrc1, const Fw8u  *pSrc2  , Fw8u  *pDst, int len );
FwStatus STDCALL fwsOr_16u                ( const Fw16u *pSrc1, const Fw16u *pSrc2  , Fw16u *pDst, int len );
FwStatus STDCALL fwsOr_32u                ( const Fw32u *pSrc1, const Fw32u *pSrc2  , Fw32u *pDst, int len );

FwStatus STDCALL fwsOr_8u_I               ( const Fw8u  *pSrc ,       Fw8u  *pSrcDst,               int len );
FwStatus STDCALL fwsOr_16u_I              ( const Fw16u *pSrc ,       Fw16u *pSrcDst,               int len );
FwStatus STDCALL fwsOr_32u_I              ( const Fw32u *pSrc ,       Fw32u *pSrcDst,               int len );

////////////////////////////////////////////////////////////////
//                        Xor
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsXor_8u                ( const Fw8u  *pSrc1, const Fw8u  *pSrc2  , Fw8u  *pDst, int len );
FwStatus STDCALL fwsXor_16u               ( const Fw16u *pSrc1, const Fw16u *pSrc2  , Fw16u *pDst, int len );
FwStatus STDCALL fwsXor_32u               ( const Fw32u *pSrc1, const Fw32u *pSrc2  , Fw32u *pDst, int len );

FwStatus STDCALL fwsXor_8u_I              ( const Fw8u  *pSrc ,       Fw8u  *pSrcDst,               int len );
FwStatus STDCALL fwsXor_16u_I             ( const Fw16u *pSrc ,       Fw16u *pSrcDst,               int len );
FwStatus STDCALL fwsXor_32u_I             ( const Fw32u *pSrc ,       Fw32u *pSrcDst,               int len );

////////////////////////////////////////////////////////////////
//                        AndC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAndC_8u               ( const Fw8u  *pSrc, Fw8u  val, Fw8u  *pDst   , int len );
FwStatus STDCALL fwsAndC_16u              ( const Fw16u *pSrc, Fw16u val, Fw16u *pDst   , int len );
FwStatus STDCALL fwsAndC_32u              ( const Fw32u *pSrc, Fw32u val, Fw32u *pDst   , int len );

FwStatus STDCALL fwsAndC_8u_I             (                     Fw8u  val, Fw8u  *pSrcDst, int len );
FwStatus STDCALL fwsAndC_16u_I            (                     Fw16u val, Fw16u *pSrcDst, int len );
FwStatus STDCALL fwsAndC_32u_I            (                     Fw32u val, Fw32u *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        OrC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsOrC_8u                ( const Fw8u  *pSrc, Fw8u  val, Fw8u  *pDst   , int len );
FwStatus STDCALL fwsOrC_16u               ( const Fw16u *pSrc, Fw16u val, Fw16u *pDst   , int len );
FwStatus STDCALL fwsOrC_32u               ( const Fw32u *pSrc, Fw32u val, Fw32u *pDst   , int len );

FwStatus STDCALL fwsOrC_8u_I              (                     Fw8u  val, Fw8u  *pSrcDst, int len );
FwStatus STDCALL fwsOrC_16u_I             (                     Fw16u val, Fw16u *pSrcDst, int len );
FwStatus STDCALL fwsOrC_32u_I             (                     Fw32u val, Fw32u *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        XorC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsXorC_8u               ( const Fw8u  *pSrc, Fw8u  val, Fw8u  *pDst   , int len );
FwStatus STDCALL fwsXorC_16u              ( const Fw16u *pSrc, Fw16u val, Fw16u *pDst   , int len );
FwStatus STDCALL fwsXorC_32u              ( const Fw32u *pSrc, Fw32u val, Fw32u *pDst   , int len );

FwStatus STDCALL fwsXorC_8u_I             (                     Fw8u  val, Fw8u  *pSrcDst, int len );
FwStatus STDCALL fwsXorC_16u_I            (                     Fw16u val, Fw16u *pSrcDst, int len );
FwStatus STDCALL fwsXorC_32u_I            (                     Fw32u val, Fw32u *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        Not
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNot_8u                ( const Fw8u  *pSrc   , Fw8u  *pDst, int len );
FwStatus STDCALL fwsNot_16u               ( const Fw16u *pSrc   , Fw16u *pDst, int len );
FwStatus STDCALL fwsNot_32u               ( const Fw32u *pSrc   , Fw32u *pDst, int len );

FwStatus STDCALL fwsNot_8u_I              (       Fw8u  *pSrcDst,               int len );
FwStatus STDCALL fwsNot_16u_I             (       Fw16u *pSrcDst,               int len );
FwStatus STDCALL fwsNot_32u_I             (       Fw32u *pSrcDst,               int len );

////////////////////////////////////////////////////////////////
//                        LShiftC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsLShiftC_8u            ( const Fw8u  *pSrc, int val, Fw8u  *pDst   , int len );
FwStatus STDCALL fwsLShiftC_16s           ( const Fw16s *pSrc, int val, Fw16s *pDst   , int len );
FwStatus STDCALL fwsLShiftC_16u           ( const Fw16u *pSrc, int val, Fw16u *pDst   , int len );
FwStatus STDCALL fwsLShiftC_32s           ( const Fw32s *pSrc, int val, Fw32s *pDst   , int len );

FwStatus STDCALL fwsLShiftC_8u_I          (                     int val, Fw8u  *pSrcDst, int len );
FwStatus STDCALL fwsLShiftC_16u_I         (                     int val, Fw16u *pSrcDst, int len );
FwStatus STDCALL fwsLShiftC_16s_I         (                     int val, Fw16s *pSrcDst, int len );
FwStatus STDCALL fwsLShiftC_32s_I         (                     int val, Fw32s *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        RShiftC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsRShiftC_8u            ( const Fw8u  *pSrc, int val, Fw8u  *pDst   , int len );
FwStatus STDCALL fwsRShiftC_16s           ( const Fw16s *pSrc, int val, Fw16s *pDst   , int len );
FwStatus STDCALL fwsRShiftC_16u           ( const Fw16u *pSrc, int val, Fw16u *pDst   , int len );
FwStatus STDCALL fwsRShiftC_32s           ( const Fw32s *pSrc, int val, Fw32s *pDst   , int len );

FwStatus STDCALL fwsRShiftC_8u_I          (                     int val, Fw8u  *pSrcDst, int len );
FwStatus STDCALL fwsRShiftC_16u_I         (                     int val, Fw16u *pSrcDst, int len );
FwStatus STDCALL fwsRShiftC_16s_I         (                     int val, Fw16s *pSrcDst, int len );
FwStatus STDCALL fwsRShiftC_32s_I         (                     int val, Fw32s *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        Mul
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsMul_16s               ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len );
FwStatus STDCALL fwsMul_32f               ( const Fw32f  *pSrc1, const Fw32f  *pSrc2  , Fw32f  *pDst, int len );
FwStatus STDCALL fwsMul_64f               ( const Fw64f  *pSrc1, const Fw64f  *pSrc2  , Fw64f  *pDst, int len );
FwStatus STDCALL fwsMul_32fc              ( const Fw32fc *pSrc1, const Fw32fc *pSrc2  , Fw32fc *pDst, int len );
FwStatus STDCALL fwsMul_64fc              ( const Fw64fc *pSrc1, const Fw64fc *pSrc2  , Fw64fc *pDst, int len );

FwStatus STDCALL fwsMul_8u16u             ( const Fw8u   *pSrc1, const Fw8u   *pSrc2  , Fw16u  *pDst, int len );
FwStatus STDCALL fwsMul_16s32f            ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw32f  *pDst, int len );

FwStatus STDCALL fwsMul_16s_I             ( const Fw16s  *pSrc,        Fw16s  *pSrcDst,                int len );
FwStatus STDCALL fwsMul_32f_I             ( const Fw32f  *pSrc,        Fw32f  *pSrcDst,                int len );
FwStatus STDCALL fwsMul_64f_I             ( const Fw64f  *pSrc,        Fw64f  *pSrcDst,                int len );
FwStatus STDCALL fwsMul_32fc_I            ( const Fw32fc *pSrc,        Fw32fc *pSrcDst,                int len );
FwStatus STDCALL fwsMul_64fc_I            ( const Fw64fc *pSrc,        Fw64fc *pSrcDst,                int len );

FwStatus STDCALL fwsMul_8u_Sfs            ( const Fw8u   *pSrc1, const Fw8u   *pSrc2  , Fw8u   *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMul_16s_Sfs           ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMul_32s_Sfs           ( const Fw32s  *pSrc1, const Fw32s  *pSrc2  , Fw32s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMul_16sc_Sfs          ( const Fw16sc *pSrc1, const Fw16sc *pSrc2  , Fw16sc *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMul_32sc_Sfs          ( const Fw32sc *pSrc1, const Fw32sc *pSrc2  , Fw32sc *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsMul_16u16s_Sfs        ( const Fw16u  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMul_16s32s_Sfs        ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw32s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMul_32s32sc_Sfs       ( const Fw32s  *pSrc1, const Fw32sc *pSrc2  , Fw32sc *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsMul_8u_ISfs           ( const Fw8u   *pSrc,        Fw8u   *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsMul_16s_ISfs          ( const Fw16s  *pSrc,        Fw16s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsMul_32s_ISfs          ( const Fw32s  *pSrc,        Fw32s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsMul_16sc_ISfs         ( const Fw16sc *pSrc,        Fw16sc *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsMul_32sc_ISfs         ( const Fw32sc *pSrc,        Fw32sc *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsMul_32s32sc_ISfs      ( const Fw32s  *pSrc,        Fw32sc *pSrcDst,                int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        MulC
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMulC_32f              ( const Fw32f  *pSrc, Fw32f  val, Fw32f  *pDst   , int len );
FwStatus STDCALL fwsMulC_64f              ( const Fw64f  *pSrc, Fw64f  val, Fw64f  *pDst   , int len );
FwStatus STDCALL fwsMulC_32fc             ( const Fw32fc *pSrc, Fw32fc val, Fw32fc *pDst   , int len );
FwStatus STDCALL fwsMulC_64fc             ( const Fw64fc *pSrc, Fw64fc val, Fw64fc *pDst   , int len );

FwStatus STDCALL fwsMulC_16s_I            (                      Fw16s  val, Fw16s  *pSrcDst, int len );
FwStatus STDCALL fwsMulC_32f_I            (                      Fw32f  val, Fw32f  *pSrcDst, int len );
FwStatus STDCALL fwsMulC_64f_I            (                      Fw64f  val, Fw64f  *pSrcDst, int len );
FwStatus STDCALL fwsMulC_32fc_I           (                      Fw32fc val, Fw32fc *pSrcDst, int len );
FwStatus STDCALL fwsMulC_64fc_I           (                      Fw64fc val, Fw64fc *pSrcDst, int len );

FwStatus STDCALL fwsMulC_8u_Sfs           ( const Fw8u   *pSrc, Fw8u   val, Fw8u   *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsMulC_16s_Sfs          ( const Fw16s  *pSrc, Fw16s  val, Fw16s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsMulC_32s_Sfs          ( const Fw32s  *pSrc, Fw32s  val, Fw32s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsMulC_16sc_Sfs         ( const Fw16sc *pSrc, Fw16sc val, Fw16sc *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsMulC_32sc_Sfs         ( const Fw32sc *pSrc, Fw32sc val, Fw32sc *pDst   , int len, int scaleFactor );

FwStatus STDCALL fwsMulC_8u_ISfs          (                      Fw8u   val, Fw8u   *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsMulC_16s_ISfs         (                      Fw16s  val, Fw16s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsMulC_32s_ISfs         (                      Fw32s  val, Fw32s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsMulC_16sc_ISfs        (                      Fw16sc val, Fw16sc *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL fwsMulC_32sc_ISfs        (                      Fw32sc val, Fw32sc *pSrcDst, int len, int scaleFactor );

FwStatus STDCALL fwsMulC_32f16s_Sfs       ( const Fw32f  *pSrc, Fw32f  val, Fw16s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL fwsMulC_Low_32f16s       ( const Fw32f  *pSrc, Fw32f  val, Fw16s  *pDst   , int len );

////////////////////////////////////////////////////////////////
//                        Abs
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsAbs_16s               ( const Fw16s *pSrc   ,Fw16s *pDst, int len );
FwStatus STDCALL fwsAbs_32s               ( const Fw32s *pSrc   ,Fw32s *pDst, int len );
FwStatus STDCALL fwsAbs_32f               ( const Fw32f *pSrc   ,Fw32f *pDst, int len );
FwStatus STDCALL fwsAbs_64f               ( const Fw64f *pSrc   ,Fw64f *pDst, int len );

FwStatus STDCALL fwsAbs_16s_I             (       Fw16s *pSrcDst,              int len );
FwStatus STDCALL fwsAbs_32s_I             (       Fw32s *pSrcDst,              int len );
FwStatus STDCALL fwsAbs_32f_I             (       Fw32f *pSrcDst,              int len );
FwStatus STDCALL fwsAbs_64f_I             (       Fw64f *pSrcDst,              int len );

////////////////////////////////////////////////////////////////
//                        Sqrt
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSqrt_32f              ( const Fw32f  *pSrc   , Fw32f  *pDst, int len );
FwStatus STDCALL fwsSqrt_64f              ( const Fw64f  *pSrc   , Fw64f  *pDst, int len );
FwStatus STDCALL fwsSqrt_32fc             ( const Fw32fc *pSrc   , Fw32fc *pDst, int len );
FwStatus STDCALL fwsSqrt_64fc             ( const Fw64fc *pSrc   , Fw64fc *pDst, int len );

FwStatus STDCALL fwsSqrt_32f_I            (       Fw32f  *pSrcDst,                int len );
FwStatus STDCALL fwsSqrt_64f_I            (       Fw64f  *pSrcDst,                int len );
FwStatus STDCALL fwsSqrt_32fc_I           (       Fw32fc *pSrcDst,                int len );
FwStatus STDCALL fwsSqrt_64fc_I           (       Fw64fc *pSrcDst,                int len );

FwStatus STDCALL fwsSqrt_8u_Sfs           ( const Fw8u   *pSrc   , Fw8u   *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_16s_Sfs          ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_16u_Sfs          ( const Fw16u  *pSrc   , Fw16u  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_32s16s_Sfs       ( const Fw32s  *pSrc   , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_64s16s_Sfs       ( const Fw64s  *pSrc   , Fw16s  *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsSqrt_8u_ISfs          (       Fw8u   *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_16s_ISfs         (       Fw16s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_16u_ISfs         (       Fw16u  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_64s_Sfs          ( const Fw64s  *pSrc   , Fw64s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_64s_ISfs         (       Fw64s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_16sc_ISfs        (       Fw16sc *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqrt_16sc_Sfs         ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Sqr
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSqr_32f               ( const Fw32f  *pSrc   , Fw32f  *pDst, int len );
FwStatus STDCALL fwsSqr_64f               ( const Fw64f  *pSrc   , Fw64f  *pDst, int len );
FwStatus STDCALL fwsSqr_32fc              ( const Fw32fc *pSrc   , Fw32fc *pDst, int len );
FwStatus STDCALL fwsSqr_64fc              ( const Fw64fc *pSrc   , Fw64fc *pDst, int len );

FwStatus STDCALL fwsSqr_32f_I             (       Fw32f  *pSrcDst,                int len );
FwStatus STDCALL fwsSqr_64f_I             (       Fw64f  *pSrcDst,                int len );
FwStatus STDCALL fwsSqr_32fc_I            (       Fw32fc *pSrcDst,                int len );
FwStatus STDCALL fwsSqr_64fc_I            (       Fw64fc *pSrcDst,                int len );

FwStatus STDCALL fwsSqr_8u_Sfs            ( const Fw8u   *pSrc   , Fw8u   *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqr_16s_Sfs           ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsSqr_16u_Sfs           ( const Fw16u  *pSrc   , Fw16u  *pDst, int len, int scaleFactor );
FwStatus STDCALL  fwsSqr_16sc_Sfs         ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsSqr_8u_ISfs           (       Fw8u   *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqr_16s_ISfs          (       Fw16s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL fwsSqr_16u_ISfs          (       Fw16u  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL  fwsSqr_16sc_ISfs        (       Fw16sc *pSrcDst,                int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Normalize
////////////////////////////////////////////////////////////////


FwStatus STDCALL  fwsNormalize_32f        ( const Fw32f  *pSrc, Fw32f  *pDst, int len, Fw32f  vsub, Fw32f vdiv );
FwStatus STDCALL  fwsNormalize_64f        ( const Fw64f  *pSrc, Fw64f  *pDst, int len, Fw64f  vsub, Fw64f vdiv );
FwStatus STDCALL  fwsNormalize_32fc       ( const Fw32fc *pSrc, Fw32fc *pDst, int len, Fw32fc vsub, Fw32f vdiv );
FwStatus STDCALL  fwsNormalize_64fc       ( const Fw64fc *pSrc, Fw64fc *pDst, int len, Fw64fc vsub, Fw64f vdiv );

FwStatus STDCALL  fwsNormalize_16s_Sfs    ( const Fw16s  *pSrc, Fw16s  *pDst, int len, Fw16s  vsub, int vdiv, int scaleFactor );
FwStatus STDCALL  fwsNormalize_16sc_Sfs   ( const Fw16sc *pSrc, Fw16sc *pDst, int len, Fw16sc vsub, int vdiv, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Div
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwsDiv_32f              ( const Fw32f  *pSrc1, const Fw32f  *pSrc2  , Fw32f  *pDst, int len );
FwStatus STDCALL  fwsDiv_64f              ( const Fw64f  *pSrc1, const Fw64f  *pSrc2  , Fw64f  *pDst, int len );
FwStatus STDCALL  fwsDiv_32fc             ( const Fw32fc *pSrc1, const Fw32fc *pSrc2  , Fw32fc *pDst, int len );
FwStatus STDCALL  fwsDiv_64fc             ( const Fw64fc *pSrc1, const Fw64fc *pSrc2  , Fw64fc *pDst, int len );

FwStatus STDCALL  fwsDiv_32f_I            ( const Fw32f  *pSrc ,       Fw32f  *pSrcDst,                int len );
FwStatus STDCALL  fwsDiv_64f_I            ( const Fw64f  *pSrc ,       Fw64f  *pSrcDst,                int len );
FwStatus STDCALL  fwsDiv_32fc_I           ( const Fw32fc *pSrc ,       Fw32fc *pSrcDst,                int len );
FwStatus STDCALL  fwsDiv_64fc_I           ( const Fw64fc *pSrc ,       Fw64fc *pSrcDst,                int len );

FwStatus STDCALL  fwsDiv_8u_Sfs           ( const Fw8u   *pSrc1, const Fw8u   *pSrc2  , Fw8u   *pDst, int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_16s_Sfs          ( const Fw16s  *pSrc1, const Fw16s  *pSrc2  , Fw16s  *pDst, int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_32s_Sfs          ( const Fw32s  *pSrc1, const Fw32s  *pSrc2  , Fw32s  *pDst, int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_16sc_Sfs         ( const Fw16sc *pSrc1, const Fw16sc *pSrc2  , Fw16sc *pDst, int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_32s16s_Sfs       ( const Fw16s  *pSrc1, const Fw32s  *pSrc2  , Fw16s  *pDst, int len, int scaleFactor );

FwStatus STDCALL  fwsDiv_8u_ISfs          ( const Fw8u   *pSrc ,       Fw8u   *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_16s_ISfs         ( const Fw16s  *pSrc ,       Fw16s  *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_16sc_ISfs        ( const Fw16sc *pSrc ,       Fw16sc *pSrcDst,                int len, int scaleFactor );
FwStatus STDCALL  fwsDiv_32s_ISfs         ( const Fw32s  *pSrc ,       Fw32s  *pSrcDst,                int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        DivC
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwsDivC_32f             ( const Fw32f  *pSrc, Fw32f  val, Fw32f  *pDst   , int len );
FwStatus STDCALL  fwsDivC_64f             ( const Fw64f  *pSrc, Fw64f  val, Fw64f  *pDst   , int len );
FwStatus STDCALL  fwsDivC_32fc            ( const Fw32fc *pSrc, Fw32fc val, Fw32fc *pDst   , int len );
FwStatus STDCALL  fwsDivC_64fc            ( const Fw64fc *pSrc, Fw64fc val, Fw64fc *pDst   , int len );

FwStatus STDCALL  fwsDivC_32f_I           (                      Fw32f  val, Fw32f  *pSrcDst, int len );
FwStatus STDCALL  fwsDivC_64f_I           (                      Fw64f  val, Fw64f  *pSrcDst, int len );
FwStatus STDCALL  fwsDivC_32fc_I          (                      Fw32fc val, Fw32fc *pSrcDst, int len );
FwStatus STDCALL  fwsDivC_64fc_I          (                      Fw64fc val, Fw64fc *pSrcDst, int len );

FwStatus STDCALL  fwsDivC_8u_Sfs          ( const Fw8u   *pSrc, Fw8u   val, Fw8u   *pDst   , int len, int scaleFactor );
FwStatus STDCALL  fwsDivC_16s_Sfs         ( const Fw16s  *pSrc, Fw16s  val, Fw16s  *pDst   , int len, int scaleFactor );
FwStatus STDCALL  fwsDivC_16sc_Sfs        ( const Fw16sc *pSrc, Fw16sc val, Fw16sc *pDst   , int len, int scaleFactor );

FwStatus STDCALL  fwsDivC_8u_ISfs         (                      Fw8u   val, Fw8u   *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL  fwsDivC_16s_ISfs        (                      Fw16s  val, Fw16s  *pSrcDst, int len, int scaleFactor );
FwStatus STDCALL  fwsDivC_16sc_ISfs       (                      Fw16sc val, Fw16sc *pSrcDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        DivCRev
////////////////////////////////////////////////////////////////

FwStatus STDCALL  fwsDivCRev_16u          ( const Fw16u *pSrc, Fw16u val, Fw16u *pDst   , int len );
FwStatus STDCALL  fwsDivCRev_32f          ( const Fw32f *pSrc, Fw32f val, Fw32f *pDst   , int len );

FwStatus STDCALL  fwsDivCRev_16u_I        (                     Fw16u val, Fw16u *pSrcDst, int len );
FwStatus STDCALL  fwsDivCRev_32f_I        (                     Fw32f val, Fw32f *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        Cubrt
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsCubrt_32f             ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCubrt_32s16s_Sfs      ( const Fw32s *pSrc, Fw16s *pDst, int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Exp
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsExp_32f               ( const Fw32f *pSrc   , Fw32f *pDst, int len );
FwStatus STDCALL fwsExp_64f               ( const Fw64f *pSrc   , Fw64f *pDst, int len );
FwStatus STDCALL fwsExp_32f64f            ( const Fw32f *pSrc   , Fw64f *pDst, int len );

FwStatus STDCALL fwsExp_32f_I             (       Fw32f *pSrcDst,               int len );
FwStatus STDCALL fwsExp_64f_I             (       Fw64f *pSrcDst,               int len );

FwStatus STDCALL fwsExp_16s_Sfs           ( const Fw16s *pSrc   , Fw16s *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsExp_32s_Sfs           ( const Fw32s *pSrc   , Fw32s *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsExp_64s_Sfs           ( const Fw64s *pSrc   , Fw64s *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsExp_16s_ISfs          (       Fw16s *pSrcDst,               int len, int scaleFactor );
FwStatus STDCALL fwsExp_32s_ISfs          (       Fw32s *pSrcDst,               int len, int scaleFactor );
FwStatus STDCALL fwsExp_64s_ISfs          (       Fw64s *pSrcDst,               int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Ln
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsLn_32f                ( const Fw32f *pSrc   , Fw32f *pDst, int len );
FwStatus STDCALL fwsLn_64f                ( const Fw64f *pSrc   , Fw64f *pDst, int len );
FwStatus STDCALL fwsLn_64f32f             ( const Fw64f *pSrc   , Fw32f *pDst, int len );

FwStatus STDCALL fwsLn_32f_I              (       Fw32f *pSrcDst,               int len );
FwStatus STDCALL fwsLn_64f_I              (       Fw64f *pSrcDst,               int len );

FwStatus STDCALL fwsLn_16s_Sfs            ( const Fw16s *pSrc   , Fw16s *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsLn_32s_Sfs            ( const Fw32s *pSrc   , Fw32s *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsLn_32s16s_Sfs         ( const Fw32s *pSrc   , Fw16s *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsLn_16s_ISfs           (       Fw16s *pSrcDst,               int len, int scaleFactor );
FwStatus STDCALL fwsLn_32s_ISfs           (       Fw32s *pSrcDst,               int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        10Log10
////////////////////////////////////////////////////////////////

FwStatus STDCALL fws10Log10_32s_Sfs       ( const Fw32s *pSrc   ,Fw32s *pDst, int len, int scaleFactor );
FwStatus STDCALL fws10Log10_32s_ISfs      (       Fw32s *pSrcDst,              int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Arctan
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsArctan_32f            ( const Fw32f *pSrc   , Fw32f *pDst, int len );
FwStatus STDCALL fwsArctan_64f            ( const Fw64f *pSrc   , Fw64f *pDst, int len );
FwStatus STDCALL fwsArctan_32f_I          (       Fw32f *pSrcDst,               int len );
FwStatus STDCALL fwsArctan_64f_I          (       Fw64f *pSrcDst,               int len );

////////////////////////////////////////////////////////////////
//                        Threshold_LTVal
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_LTVal_16s   ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, Fw16s level, Fw16s  value );
FwStatus STDCALL fwsThreshold_LTVal_32f   ( const Fw32f  *pSrc   , Fw32f  *pDst, int len, Fw32f level, Fw32f  value );
FwStatus STDCALL fwsThreshold_LTVal_64f   ( const Fw64f  *pSrc   , Fw64f  *pDst, int len, Fw64f level, Fw64f  value );
FwStatus STDCALL fwsThreshold_LTVal_16sc  ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, Fw16s level, Fw16sc value );
FwStatus STDCALL fwsThreshold_LTVal_32fc  ( const Fw32fc *pSrc   , Fw32fc *pDst, int len, Fw32f level, Fw32fc value );
FwStatus STDCALL fwsThreshold_LTVal_64fc  ( const Fw64fc *pSrc   , Fw64fc *pDst, int len, Fw64f level, Fw64fc value );

FwStatus STDCALL fwsThreshold_LTVal_16s_I (       Fw16s  *pSrcDst,                int len, Fw16s level, Fw16s  value );
FwStatus STDCALL fwsThreshold_LTVal_32f_I (       Fw32f  *pSrcDst,                int len, Fw32f level, Fw32f  value );
FwStatus STDCALL fwsThreshold_LTVal_64f_I (       Fw64f  *pSrcDst,                int len, Fw64f level, Fw64f  value );
FwStatus STDCALL fwsThreshold_LTVal_16sc_I(       Fw16sc *pSrcDst,                int len, Fw16s level, Fw16sc value );
FwStatus STDCALL fwsThreshold_LTVal_32fc_I(       Fw32fc *pSrcDst,                int len, Fw32f level, Fw32fc value );
FwStatus STDCALL fwsThreshold_LTVal_64fc_I(       Fw64fc *pSrcDst,                int len, Fw64f level, Fw64fc value );

////////////////////////////////////////////////////////////////
//                        Threshold_GTVal
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_GTVal_16s   ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, Fw16s level, Fw16s  value );
FwStatus STDCALL fwsThreshold_GTVal_32f   ( const Fw32f  *pSrc   , Fw32f  *pDst, int len, Fw32f level, Fw32f  value );
FwStatus STDCALL fwsThreshold_GTVal_64f   ( const Fw64f  *pSrc   , Fw64f  *pDst, int len, Fw64f level, Fw64f  value );
FwStatus STDCALL fwsThreshold_GTVal_16sc  ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, Fw16s level, Fw16sc value );
FwStatus STDCALL fwsThreshold_GTVal_32fc  ( const Fw32fc *pSrc   , Fw32fc *pDst, int len, Fw32f level, Fw32fc value );
FwStatus STDCALL fwsThreshold_GTVal_64fc  ( const Fw64fc *pSrc   , Fw64fc *pDst, int len, Fw64f level, Fw64fc value );

FwStatus STDCALL fwsThreshold_GTVal_16s_I (       Fw16s  *pSrcDst,                int len, Fw16s level, Fw16s  value );
FwStatus STDCALL fwsThreshold_GTVal_32f_I (       Fw32f  *pSrcDst,                int len, Fw32f level, Fw32f  value );
FwStatus STDCALL fwsThreshold_GTVal_64f_I (       Fw64f  *pSrcDst,                int len, Fw64f level, Fw64f  value );
FwStatus STDCALL fwsThreshold_GTVal_16sc_I(       Fw16sc *pSrcDst,                int len, Fw16s level, Fw16sc value );
FwStatus STDCALL fwsThreshold_GTVal_32fc_I(       Fw32fc *pSrcDst,                int len, Fw32f level, Fw32fc value );
FwStatus STDCALL fwsThreshold_GTVal_64fc_I(       Fw64fc *pSrcDst,                int len, Fw64f level, Fw64fc value );

////////////////////////////////////////////////////////////////
//                        Threshold_LTValGTVal
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_LTValGTVal_16s  ( const Fw16s *pSrc   , Fw16s *pDst, int len, Fw16s levelLT, Fw16s valueLT, Fw16s levelGT, Fw16s valueGT );
FwStatus STDCALL fwsThreshold_LTValGTVal_32s  ( const Fw32s *pSrc   , Fw32s *pDst, int len, Fw32s levelLT, Fw32s valueLT, Fw32s levelGT, Fw32s valueGT );
FwStatus STDCALL fwsThreshold_LTValGTVal_32f  ( const Fw32f *pSrc   , Fw32f *pDst, int len, Fw32f levelLT, Fw32f valueLT, Fw32f levelGT, Fw32f valueGT );
FwStatus STDCALL fwsThreshold_LTValGTVal_64f  ( const Fw64f *pSrc   , Fw64f *pDst, int len, Fw64f levelLT, Fw64f valueLT, Fw64f levelGT, Fw64f valueGT );

FwStatus STDCALL fwsThreshold_LTValGTVal_16s_I(       Fw16s *pSrcDst,               int len, Fw16s levelLT, Fw16s valueLT, Fw16s levelGT, Fw16s valueGT );
FwStatus STDCALL fwsThreshold_LTValGTVal_32s_I(       Fw32s *pSrcDst,               int len, Fw32s levelLT, Fw32s valueLT, Fw32s levelGT, Fw32s valueGT );
FwStatus STDCALL fwsThreshold_LTValGTVal_32f_I(       Fw32f *pSrcDst,               int len, Fw32f levelLT, Fw32f valueLT, Fw32f levelGT, Fw32f valueGT );
FwStatus STDCALL fwsThreshold_LTValGTVal_64f_I(       Fw64f *pSrcDst,               int len, Fw64f levelLT, Fw64f valueLT, Fw64f levelGT, Fw64f valueGT );

////////////////////////////////////////////////////////////////
//                        Threshold_LT
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_LT_16s      ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, Fw16s level );
FwStatus STDCALL fwsThreshold_LT_32s      ( const Fw32s  *pSrc   , Fw32s  *pDst, int len, Fw32s level );
FwStatus STDCALL fwsThreshold_LT_32f      ( const Fw32f  *pSrc   , Fw32f  *pDst, int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LT_64f      ( const Fw64f  *pSrc   , Fw64f  *pDst, int len, Fw64f level );
FwStatus STDCALL fwsThreshold_LT_32fc     ( const Fw32fc *pSrc   , Fw32fc *pDst, int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LT_64fc     ( const Fw64fc *pSrc   , Fw64fc *pDst, int len, Fw64f level );
FwStatus STDCALL fwsThreshold_LT_16sc     ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, Fw16s level );

FwStatus STDCALL fwsThreshold_LT_16s_I    (       Fw16s  *pSrcDst,                int len, Fw16s level );
FwStatus STDCALL fwsThreshold_LT_32s_I    (       Fw32s  *pSrcDst,                int len, Fw32s level );
FwStatus STDCALL fwsThreshold_LT_32f_I    (       Fw32f  *pSrcDst,                int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LT_64f_I    (       Fw64f  *pSrcDst,                int len, Fw64f level );
FwStatus STDCALL fwsThreshold_LT_32fc_I   (       Fw32fc *pSrcDst,                int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LT_64fc_I   (       Fw64fc *pSrcDst,                int len, Fw64f level );
FwStatus STDCALL fwsThreshold_LT_16sc_I   (       Fw16sc *pSrcDst,                int len, Fw16s level );

////////////////////////////////////////////////////////////////
//                        Threshold_GT
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_GT_16s      ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, Fw16s level );
FwStatus STDCALL fwsThreshold_GT_32s      ( const Fw32s  *pSrc   , Fw32s  *pDst, int len, Fw32s level );
FwStatus STDCALL fwsThreshold_GT_32f      ( const Fw32f  *pSrc   , Fw32f  *pDst, int len, Fw32f level );
FwStatus STDCALL fwsThreshold_GT_64f      ( const Fw64f  *pSrc   , Fw64f  *pDst, int len, Fw64f level );
FwStatus STDCALL fwsThreshold_GT_32fc     ( const Fw32fc *pSrc   , Fw32fc *pDst, int len, Fw32f level );
FwStatus STDCALL fwsThreshold_GT_64fc     ( const Fw64fc *pSrc   , Fw64fc *pDst, int len, Fw64f level );
FwStatus STDCALL fwsThreshold_GT_16sc     ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, Fw16s level );

FwStatus STDCALL fwsThreshold_GT_16s_I    (       Fw16s  *pSrcDst,                int len, Fw16s level );
FwStatus STDCALL fwsThreshold_GT_32s_I    (       Fw32s  *pSrcDst,                int len, Fw32s level );
FwStatus STDCALL fwsThreshold_GT_32f_I    (       Fw32f  *pSrcDst,                int len, Fw32f level );
FwStatus STDCALL fwsThreshold_GT_64f_I    (       Fw64f  *pSrcDst,                int len, Fw64f level );
FwStatus STDCALL fwsThreshold_GT_32fc_I   (       Fw32fc *pSrcDst,                int len, Fw32f level );
FwStatus STDCALL fwsThreshold_GT_64fc_I   (       Fw64fc *pSrcDst,                int len, Fw64f level );
FwStatus STDCALL fwsThreshold_GT_16sc_I   (       Fw16sc *pSrcDst,                int len, Fw16s level );

////////////////////////////////////////////////////////////////
//                        Threshold
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_16s         ( const Fw16s  *pSrc   , Fw16s  *pDst, int len, Fw16s level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_32f         ( const Fw32f  *pSrc   , Fw32f  *pDst, int len, Fw32f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_64f         ( const Fw64f  *pSrc   , Fw64f  *pDst, int len, Fw64f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_32fc        ( const Fw32fc *pSrc   , Fw32fc *pDst, int len, Fw32f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_64fc        ( const Fw64fc *pSrc   , Fw64fc *pDst, int len, Fw64f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_16sc        ( const Fw16sc *pSrc   , Fw16sc *pDst, int len, Fw16s level, FwCmpOp relOp );

FwStatus STDCALL fwsThreshold_16s_I       (       Fw16s  *pSrcDst,                int len, Fw16s level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_32f_I       (       Fw32f  *pSrcDst,                int len, Fw32f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_64f_I       (       Fw64f  *pSrcDst,                int len, Fw64f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_32fc_I      (       Fw32fc *pSrcDst,                int len, Fw32f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_64fc_I      (       Fw64fc *pSrcDst,                int len, Fw64f level, FwCmpOp relOp );
FwStatus STDCALL fwsThreshold_16sc_I      (       Fw16sc *pSrcDst,                int len, Fw16s level, FwCmpOp relOp );

////////////////////////////////////////////////////////////////
//                        Threshold_LTInv
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsThreshold_LTInv_32f   ( const Fw32f  *pSrc   , Fw32f  *pDst, int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LTInv_64f   ( const Fw64f  *pSrc   , Fw64f  *pDst, int len, Fw64f level );
FwStatus STDCALL fwsThreshold_LTInv_32fc  ( const Fw32fc *pSrc   , Fw32fc *pDst, int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LTInv_64fc  ( const Fw64fc *pSrc   , Fw64fc *pDst, int len, Fw64f level );

FwStatus STDCALL fwsThreshold_LTInv_32f_I (       Fw32f  *pSrcDst,                int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LTInv_64f_I (       Fw64f  *pSrcDst,                int len, Fw64f level );
FwStatus STDCALL fwsThreshold_LTInv_32fc_I(       Fw32fc *pSrcDst,                int len, Fw32f level );
FwStatus STDCALL fwsThreshold_LTInv_64fc_I(       Fw64fc *pSrcDst,                int len, Fw64f level );

////////////////////////////////////////////////////////////////
//                        Magnitude
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMagnitude_32f         ( const Fw32f  *pSrcRe, const Fw32f *pSrcIm, Fw32f *pDst, int len );
FwStatus STDCALL fwsMagnitude_64f         ( const Fw64f  *pSrcRe, const Fw64f *pSrcIm, Fw64f *pDst, int len );
FwStatus STDCALL fwsMagnitude_32fc        ( const Fw32fc *pSrc  ,       Fw32f *pDst  ,               int len );
FwStatus STDCALL fwsMagnitude_64fc        ( const Fw64fc *pSrc  ,       Fw64f *pDst  ,               int len );
FwStatus STDCALL fwsMagnitude_16s32f      ( const Fw16s  *pSrcRe, const Fw16s *pSrcIm, Fw32f *pDst, int len );
FwStatus STDCALL fwsMagnitude_16sc32f     ( const Fw16sc *pSrc  ,       Fw32f *pDst  ,               int len );

FwStatus STDCALL fwsMagnitude_16s_Sfs     ( const Fw16s  *pSrcRe, const Fw16s *pSrcIm, Fw16s *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsMagnitude_16sc_Sfs    ( const Fw16sc *pSrc  ,       Fw16s *pDst  ,               int len, int scaleFactor );
FwStatus STDCALL fwsMagnitude_32sc_Sfs    ( const Fw32sc *pSrc  ,       Fw32s *pDst  ,               int len, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Convert
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsConvert_8s16s         ( const Fw8s  *pSrc, Fw16s *pDst, int len );
FwStatus STDCALL fwsConvert_8u16s         ( const Fw8s  *pSrc, Fw16s *pDst, int len );
FwStatus STDCALL fwsConvert_8s32f         ( const Fw8s  *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsConvert_8u32f         ( const Fw8u  *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsConvert_16s32s        ( const Fw16s *pSrc, Fw32s *pDst, int len );
FwStatus STDCALL fwsConvert_16u32s        ( const Fw16u *pSrc, Fw32s *pDst, int len );
FwStatus STDCALL fwsConvert_16s32f        ( const Fw16s *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsConvert_16u32f        ( const Fw16u *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsConvert_32s16s        ( const Fw32s *pSrc, Fw16s *pDst, int len );
FwStatus STDCALL fwsConvert_32u16s        ( const Fw32u *pSrc, Fw16s *pDst, int len );
FwStatus STDCALL fwsConvert_32s32f        ( const Fw32s *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsConvert_32u32f        ( const Fw32u *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsConvert_32s64f        ( const Fw32s *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsConvert_32u64f        ( const Fw32u *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsConvert_32f64f        ( const Fw32f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsConvert_64f32f        ( const Fw64f *pSrc, Fw32f *pDst, int len );

FwStatus STDCALL fwsConvert_16s32f_Sfs    ( const Fw16s *pSrc, Fw32f *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsConvert_16u32f_Sfs    ( const Fw16u *pSrc, Fw32f *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsConvert_16s64f_Sfs    ( const Fw16s *pSrc, Fw64f *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsConvert_32s16s_Sfs    ( const Fw32s *pSrc, Fw16s *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsConvert_32s32f_Sfs    ( const Fw32s *pSrc, Fw32f *pDst, int len, int scaleFactor );
FwStatus STDCALL fwsConvert_32s64f_Sfs    ( const Fw32s *pSrc, Fw64f *pDst, int len, int scaleFactor );

FwStatus STDCALL fwsConvert_32f8s_Sfs     ( const Fw32f *pSrc, Fw8s  *pDst, int len, FwRoundMode rndMode, int scaleFactor );
FwStatus STDCALL fwsConvert_32f8u_Sfs     ( const Fw32f *pSrc, Fw8u  *pDst, int len, FwRoundMode rndMode, int scaleFactor );
FwStatus STDCALL fwsConvert_32f16s_Sfs    ( const Fw32f *pSrc, Fw16s *pDst, int len, FwRoundMode rndMode, int scaleFactor );
FwStatus STDCALL fwsConvert_32f16u_Sfs    ( const Fw32f *pSrc, Fw16u *pDst, int len, FwRoundMode rndMode, int scaleFactor );
FwStatus STDCALL fwsConvert_32f32s_Sfs    ( const Fw32f *pSrc, Fw32s *pDst, int len, FwRoundMode rndMode, int scaleFactor );
FwStatus STDCALL fwsConvert_64s32s_Sfs    ( const Fw64s *pSrc, Fw32s *pDst, int len, FwRoundMode rndMode, int scaleFactor );
FwStatus STDCALL fwsConvert_64f32s_Sfs    ( const Fw64f *pSrc, Fw32s *pDst, int len, FwRoundMode rndMode, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Max
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMax_16s               ( const Fw16s *pSrc, int len, Fw16s *pMax );
FwStatus STDCALL fwsMax_32s               ( const Fw32s *pSrc, int len, Fw32s *pMax );
FwStatus STDCALL fwsMax_32f               ( const Fw32f *pSrc, int len, Fw32f *pMax );
FwStatus STDCALL fwsMax_64f               ( const Fw64f *pSrc, int len, Fw64f *pMax );
FwStatus STDCALL fwsMax_8s                ( const Fw8s  *pSrc, int len, Fw8s  *pMax );
FwStatus STDCALL fwsMax_64u               ( const Fw64u *pSrc, int len, Fw64u *pMax );

////////////////////////////////////////////////////////////////
//                        MaxIndx
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMaxIndx_16s           ( const Fw16s *pSrc, int len, Fw16s *pMax, int *pIndx );
FwStatus STDCALL fwsMaxIndx_32s           ( const Fw32s *pSrc, int len, Fw32s *pMax, int *pIndx );
FwStatus STDCALL fwsMaxIndx_32f           ( const Fw32f *pSrc, int len, Fw32f *pMax, int *pIndx );
FwStatus STDCALL fwsMaxIndx_64f           ( const Fw64f *pSrc, int len, Fw64f *pMax, int *pIndx );

////////////////////////////////////////////////////////////////
//                        MaxAbs
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMaxAbs_16s            ( const Fw16s *pSrc, int len, Fw16s *pMaxAbs );
FwStatus STDCALL fwsMaxAbs_32s            ( const Fw32s *pSrc, int len, Fw32s *pMaxAbs );

////////////////////////////////////////////////////////////////
//                        MaxAbsIndx
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMaxAbsIndx_16s        ( const Fw16s *pSrc, int len, Fw16s *pMaxAbs, int *pIndx );
FwStatus STDCALL fwsMaxAbsIndx_32s        ( const Fw32s *pSrc, int len, Fw32s *pMaxAbs, int *pIndx );

////////////////////////////////////////////////////////////////
//                        Min
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMin_16s               ( const Fw16s *pSrc, int len, Fw16s *pMin );
FwStatus STDCALL fwsMin_32s               ( const Fw32s *pSrc, int len, Fw32s *pMin );
FwStatus STDCALL fwsMin_32f               ( const Fw32f *pSrc, int len, Fw32f *pMin );
FwStatus STDCALL fwsMin_64f               ( const Fw64f *pSrc, int len, Fw64f *pMin );
FwStatus STDCALL fwsMin_8s                ( const Fw8s  *pSrc, int len, Fw8s  *pMin );
FwStatus STDCALL fwsMin_64u               ( const Fw64u *pSrc, int len, Fw64u *pMin );

////////////////////////////////////////////////////////////////
//                        MinIndx
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMinIndx_16s           ( const Fw16s *pSrc, int len, Fw16s *pMin, int *pIndx );
FwStatus STDCALL fwsMinIndx_32s           ( const Fw32s *pSrc, int len, Fw32s *pMin, int *pIndx );
FwStatus STDCALL fwsMinIndx_32f           ( const Fw32f *pSrc, int len, Fw32f *pMin, int *pIndx );
FwStatus STDCALL fwsMinIndx_64f           ( const Fw64f *pSrc, int len, Fw64f *pMin, int *pIndx );

////////////////////////////////////////////////////////////////
//                        MinAbs
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMinAbs_16s            ( const Fw16s *pSrc, int len, Fw16s *pMinAbs );
FwStatus STDCALL fwsMinAbs_32s            ( const Fw32s *pSrc, int len, Fw32s *pMinAbs );

////////////////////////////////////////////////////////////////
//                        MinAbsIndx
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMinAbsIndx_16s        ( const Fw16s *pSrc, int len, Fw16s *pMinAbs, int *pIndx );
FwStatus STDCALL fwsMinAbsIndx_32s        ( const Fw32s *pSrc, int len, Fw32s *pMinAbs, int *pIndx );

////////////////////////////////////////////////////////////////
//                        MinMax
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMinMax_8u             ( const Fw8u  *pSrc, int len, Fw8u  *pMin, Fw8u  *pMax );
FwStatus STDCALL fwsMinMax_16u            ( const Fw16u *pSrc, int len, Fw16u *pMin, Fw16u *pMax );
FwStatus STDCALL fwsMinMax_16s            ( const Fw16s *pSrc, int len, Fw16s *pMin, Fw16s *pMax );
FwStatus STDCALL fwsMinMax_32u            ( const Fw32u *pSrc, int len, Fw32u *pMin, Fw32u *pMax );
FwStatus STDCALL fwsMinMax_32s            ( const Fw32s *pSrc, int len, Fw32s *pMin, Fw32s *pMax );
FwStatus STDCALL fwsMinMax_32f            ( const Fw32f *pSrc, int len, Fw32f *pMin, Fw32f *pMax );
FwStatus STDCALL fwsMinMax_64f            ( const Fw64f *pSrc, int len, Fw64f *pMin, Fw64f *pMax );

////////////////////////////////////////////////////////////////
//                        MinMaxIndx
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMinMaxIndx_8u         ( const Fw8u  *pSrc, int len, Fw8u  *pMin, int *pMinIndx, Fw8u  *pMax, int *pMaxIndx );
FwStatus STDCALL fwsMinMaxIndx_16u        ( const Fw16u *pSrc, int len, Fw16u *pMin, int *pMinIndx, Fw16u *pMax, int *pMaxIndx );
FwStatus STDCALL fwsMinMaxIndx_16s        ( const Fw16s *pSrc, int len, Fw16s *pMin, int *pMinIndx, Fw16s *pMax, int *pMaxIndx );
FwStatus STDCALL fwsMinMaxIndx_32u        ( const Fw32u *pSrc, int len, Fw32u *pMin, int *pMinIndx, Fw32u *pMax, int *pMaxIndx );
FwStatus STDCALL fwsMinMaxIndx_32s        ( const Fw32s *pSrc, int len, Fw32s *pMin, int *pMinIndx, Fw32s *pMax, int *pMaxIndx );
FwStatus STDCALL fwsMinMaxIndx_32f        ( const Fw32f *pSrc, int len, Fw32f *pMin, int *pMinIndx, Fw32f *pMax, int *pMaxIndx );
FwStatus STDCALL fwsMinMaxIndx_64f        ( const Fw64f *pSrc, int len, Fw64f *pMin, int *pMinIndx, Fw64f *pMax, int *pMaxIndx );

////////////////////////////////////////////////////////////////
//                        Norm_Inf
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNorm_Inf_32f          ( const Fw32f  *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_Inf_64f          ( const Fw64f  *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_Inf_16s32f       ( const Fw16s  *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_Inf_32fc32f      ( const Fw32fc *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_Inf_64fc64f      ( const Fw64fc *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_Inf_16s32s_Sfs   ( const Fw16s  *pSrc, int len, Fw32s *pNorm,int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Norm_L1
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNorm_L1_32f           ( const Fw32f  *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_L1_64f           ( const Fw64f  *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_L1_16s32f        ( const Fw16s  *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_L1_32fc64f       ( const Fw32fc *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_L1_64fc64f       ( const Fw64fc *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_L1_16s32s_Sfs    ( const Fw16s  *pSrc, int len, Fw32s *pNorm,int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Norm_L2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNorm_L2_32f           ( const Fw32f  *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_L2_64f           ( const Fw64f  *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_L2_16s32f        ( const Fw16s  *pSrc, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNorm_L2_32fc64f       ( const Fw32fc *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_L2_64fc64f       ( const Fw64fc *pSrc, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNorm_L2_16s32s_Sfs    ( const Fw16s  *pSrc, int len, Fw32s *pNorm, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        NormDiff_Inf
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNormDiff_Inf_32f          ( const Fw32f  *pSrc1, const Fw32f  *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_Inf_64f          ( const Fw64f  *pSrc1, const Fw64f  *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_Inf_16s32f       ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_Inf_32fc32f      ( const Fw32fc *pSrc1, const Fw32fc *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_Inf_64fc64f      ( const Fw64fc *pSrc1, const Fw64fc *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_Inf_16s32s_Sfs   ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32s *pNorm, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        NormDiff_L1
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNormDiff_L1_32f       ( const Fw32f  *pSrc1, const Fw32f  *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_L1_64f       ( const Fw64f  *pSrc1, const Fw64f  *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_L1_16s32f    ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_L1_32fc64f   ( const Fw32fc *pSrc1, const Fw32fc *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_L1_64fc64f   ( const Fw64fc *pSrc1, const Fw64fc *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_L1_16s32s_Sfs( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32s *pNorm, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        NormDiff_L2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsNormDiff_L2_32f       ( const Fw32f  *pSrc1, const Fw32f  *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_L2_64f       ( const Fw64f  *pSrc1, const Fw64f  *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_L2_16s32f    ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32f *pNorm );
FwStatus STDCALL fwsNormDiff_L2_32fc64f   ( const Fw32fc *pSrc1, const Fw32fc *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_L2_64fc64f   ( const Fw64fc *pSrc1, const Fw64fc *pSrc2, int len, Fw64f *pNorm );
FwStatus STDCALL fwsNormDiff_L2_16s32s_Sfs( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32s *pNorm, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Mean
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMean_32f              ( const Fw32f  *pSrc, int len, Fw32f  *pMean,FwHintAlgorithm hint );
FwStatus STDCALL fwsMean_32fc             ( const Fw32fc *pSrc, int len, Fw32fc *pMean,FwHintAlgorithm hint );

FwStatus STDCALL fwsMean_64f              ( const Fw64f  *pSrc, int len, Fw64f  *pMean );
FwStatus STDCALL fwsMean_64fc             ( const Fw64fc *pSrc, int len, Fw64fc *pMean );

FwStatus STDCALL fwsMean_16s_Sfs          ( const Fw16s  *pSrc, int len, Fw16s  *pMean, int scaleFactor );
FwStatus STDCALL fwsMean_16sc_Sfs         ( const Fw16sc *pSrc, int len, Fw16sc *pMean, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        MaxEvery
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMaxEvery_16s_I        ( const Fw16s *pSrc, Fw16s *pSrcDst, int len );
FwStatus STDCALL fwsMaxEvery_32s_I        ( const Fw32s *pSrc, Fw32s *pSrcDst, int len );
FwStatus STDCALL fwsMaxEvery_32f_I        ( const Fw32f *pSrc, Fw32f *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        MinEvery
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMinEvery_16s_I        ( const Fw16s *pSrc, Fw16s *pSrcDst, int len );
FwStatus STDCALL fwsMinEvery_32s_I        ( const Fw32s *pSrc, Fw32s *pSrcDst, int len );
FwStatus STDCALL fwsMinEvery_32f_I        ( const Fw32f *pSrc, Fw32f *pSrcDst, int len );

////////////////////////////////////////////////////////////////
//                        DotProd
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsDotProd_16s32f            ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32f  *pDp );
FwStatus STDCALL fwsDotProd_16s64s            ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw64s  *pDp );
FwStatus STDCALL fwsDotProd_16s16sc64sc       ( const Fw16s  *pSrc1, const Fw16sc *pSrc2, int len, Fw64sc *pDp );
FwStatus STDCALL fwsDotProd_16s16sc32fc       ( const Fw16s  *pSrc1, const Fw16sc *pSrc2, int len, Fw32fc *pDp );
FwStatus STDCALL fwsDotProd_32f               ( const Fw32f  *pSrc1, const Fw32f  *pSrc2, int len, Fw32f  *pDp );
FwStatus STDCALL fwsDotProd_32f64f            ( const Fw32f  *pSrc1, const Fw32f  *pSrc2, int len, Fw64f  *pDp );
FwStatus STDCALL fwsDotProd_32f32fc           ( const Fw32f  *pSrc1, const Fw32fc *pSrc2, int len, Fw32fc *pDp );
FwStatus STDCALL fwsDotProd_32f32fc64fc       ( const Fw32f  *pSrc1, const Fw32fc *pSrc2, int len, Fw64fc *pDp );
FwStatus STDCALL fwsDotProd_64f               ( const Fw64f  *pSrc1, const Fw64f  *pSrc2, int len, Fw64f  *pDp );
FwStatus STDCALL fwsDotProd_64f64fc           ( const Fw64f  *pSrc1, const Fw64fc *pSrc2, int len, Fw64fc *pDp );
FwStatus STDCALL fwsDotProd_16sc64sc          ( const Fw16sc *pSrc1, const Fw16sc *pSrc2, int len, Fw64sc *pDp );
FwStatus STDCALL fwsDotProd_16sc32fc          ( const Fw16sc *pSrc1, const Fw16sc *pSrc2, int len, Fw32fc *pDp );
FwStatus STDCALL fwsDotProd_32fc              ( const Fw32fc *pSrc1, const Fw32fc *pSrc2, int len, Fw32fc *pDp );
FwStatus STDCALL fwsDotProd_32fc64fc          ( const Fw32fc *pSrc1, const Fw32fc *pSrc2, int len, Fw64fc *pDp );
FwStatus STDCALL fwsDotProd_64fc              ( const Fw64fc *pSrc1, const Fw64fc *pSrc2, int len, Fw64fc *pDp );

FwStatus STDCALL fwsDotProd_16s_Sfs           ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw16s  *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_16s32s_Sfs        ( const Fw16s  *pSrc1, const Fw16s  *pSrc2, int len, Fw32s  *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_16s16sc32sc_Sfs   ( const Fw16s  *pSrc1, const Fw16sc *pSrc2, int len, Fw32sc *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_16s32s32s_Sfs     ( const Fw16s  *pSrc1, const Fw32s  *pSrc2, int len, Fw32s  *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_16s16sc_Sfs       ( const Fw16s  *pSrc1, const Fw16sc *pSrc2, int len, Fw16sc *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_32s_Sfs           ( const Fw32s  *pSrc1, const Fw32s  *pSrc2, int len, Fw32s  *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_32s32sc_Sfs       ( const Fw32s  *pSrc1, const Fw32sc *pSrc2, int len, Fw32sc *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_16sc_Sfs          ( const Fw16sc *pSrc1, const Fw16sc *pSrc2, int len, Fw16sc *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_16sc32sc_Sfs      ( const Fw16sc *pSrc1, const Fw16sc *pSrc2, int len, Fw32sc *pDp, int scaleFactor );
FwStatus STDCALL fwsDotProd_32sc_Sfs          ( const Fw32sc *pSrc1, const Fw32sc *pSrc2, int len, Fw32sc *pDp, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        Sum
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSum_32f               ( const Fw32f  *pSrc, int len, Fw32f  *pSum, FwHintAlgorithm hint );
FwStatus STDCALL fwsSum_32fc              ( const Fw32fc *pSrc, int len, Fw32fc *pSum, FwHintAlgorithm hint );

FwStatus STDCALL fwsSum_64f               ( const Fw64f  *pSrc, int len, Fw64f  *pSum );
FwStatus STDCALL fwsSum_64fc              ( const Fw64fc *pSrc, int len, Fw64fc *pSum );

FwStatus STDCALL fwsSum_16s_Sfs           ( const Fw16s  *pSrc, int len, Fw16s  *pSum, int scaleFactor );
FwStatus STDCALL fwsSum_32s_Sfs           ( const Fw32s  *pSrc, int len, Fw32s  *pSum, int scaleFactor );
FwStatus STDCALL fwsSum_16s32s_Sfs        ( const Fw16s  *pSrc, int len, Fw32s  *pSum, int scaleFactor );
FwStatus STDCALL fwsSum_16sc_Sfs          ( const Fw16sc *pSrc, int len, Fw16sc *pSum, int scaleFactor );
FwStatus STDCALL fwsSum_16sc32sc_Sfs      ( const Fw16sc *pSrc, int len, Fw32sc *pSum, int scaleFactor );

////////////////////////////////////////////////////////////////
//                        StdDev
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsStdDev_32f            ( const Fw32f *pSrc, int len, Fw32f *pStdDev, FwHintAlgorithm hint );

FwStatus STDCALL fwsStdDev_64f            ( const Fw64f *pSrc, int len, Fw64f *pStdDev );

FwStatus STDCALL fwsStdDev_16s32s_Sfs     ( const Fw16s *pSrc, int len, Fw32s *pStdDev, int scaleFactor );
FwStatus STDCALL fwsStdDev_16s_Sfs        ( const Fw16s *pSrc, int len, Fw16s *pStdDev, int scaleFactor );

//Fixed accuracy arithmetic


////////////////////////////////////////////////////////////////
//                        Inv
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsInv_32f_A11           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInv_32f_A21           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInv_32f_A24           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInv_64f_A50           ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsInv_64f_A53           ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Div
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsDiv_32f_A11           ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsDiv_32f_A21           ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsDiv_32f_A24           ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsDiv_64f_A50           ( const Fw64f *pSrc1, const Fw64f *pSrc2, Fw64f *pDst, int len );
FwStatus STDCALL fwsDiv_64f_A53           ( const Fw64f *pSrc1, const Fw64f *pSrc2, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Sqrt
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsSqrt_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSqrt_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSqrt_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSqrt_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsSqrt_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        InvSqrt
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsInvSqrt_32f_A11       ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInvSqrt_32f_A21       ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInvSqrt_32f_A24       ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInvSqrt_64f_A50       ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsInvSqrt_64f_A53       ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Cbrt
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsCbrt_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCbrt_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCbrt_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCbrt_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsCbrt_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        InvCbrt
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsInvCbrt_32f_A11       ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInvCbrt_32f_A21       ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInvCbrt_32f_A24       ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsInvCbrt_64f_A50       ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsInvCbrt_64f_A53       ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Pow
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsPow_32f_A11           ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsPow_32f_A21           ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsPow_32f_A24           ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsPow_64f_A50           ( const Fw64f *pSrc1, const Fw64f *pSrc2, Fw64f *pDst, int len );
FwStatus STDCALL fwsPow_64f_A53           ( const Fw64f *pSrc1, const Fw64f *pSrc2, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Powx
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsPowx_32f_A11          ( const Fw32f *pSrc1, const Fw32f val, Fw32f *pDst, int len );
FwStatus STDCALL fwsPowx_32f_A21          ( const Fw32f *pSrc1, const Fw32f val, Fw32f *pDst, int len );
FwStatus STDCALL fwsPowx_32f_A24          ( const Fw32f *pSrc1, const Fw32f val, Fw32f *pDst, int len );
FwStatus STDCALL fwsPowx_64f_A50          ( const Fw64f *pSrc1, const Fw64f val, Fw64f *pDst, int len );
FwStatus STDCALL fwsPowx_64f_A53          ( const Fw64f *pSrc1, const Fw64f val, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Exp
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsExp_32f_A11           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsExp_32f_A21           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsExp_32f_A24           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsExp_64f_A50           ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsExp_64f_A53           ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Ln
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsLn_32f_A11            ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsLn_32f_A21            ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsLn_32f_A24            ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsLn_64f_A50            ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsLn_64f_A53            ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Log10
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsLog10_32f_A11         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsLog10_32f_A21         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsLog10_32f_A24         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsLog10_64f_A50         ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsLog10_64f_A53         ( const Fw64f *pSrc, Fw64f *pDst, int len );

//Trigonometric functions


////////////////////////////////////////////////////////////////
//                        Cos
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsCos_32f_A11           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCos_32f_A21           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCos_32f_A24           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCos_64f_A50           ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsCos_64f_A53           ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Sin
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSin_32f_A11           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSin_32f_A21           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSin_32f_A24           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSin_64f_A50           ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsSin_64f_A53           ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Tan
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsTan_32f_A11           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsTan_32f_A21           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsTan_32f_A24           ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsTan_64f_A50           ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsTan_64f_A53           ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Acos
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAcos_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAcos_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAcos_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAcos_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsAcos_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Asin
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAsin_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAsin_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAsin_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAsin_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsAsin_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Atan
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAtan_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtan_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtan_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtan_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsAtan_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Atan2
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAtan2_32f_A11         ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtan2_32f_A21         ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtan2_32f_A24         ( const Fw32f *pSrc1, const Fw32f *pSrc2, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtan2_64f_A50         ( const Fw64f *pSrc1, const Fw64f *pSrc2, Fw64f *pDst, int len );
FwStatus STDCALL fwsAtan2_64f_A53         ( const Fw64f *pSrc1, const Fw64f *pSrc2, Fw64f *pDst, int len );

//Hyperbolic Functions


////////////////////////////////////////////////////////////////
//                        Cosh
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsCosh_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCosh_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCosh_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsCosh_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsCosh_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Sinh
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSinh_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSinh_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSinh_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsSinh_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsSinh_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Tanh
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsTanh_32f_A11          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsTanh_32f_A21          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsTanh_32f_A24          ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsTanh_64f_A50          ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsTanh_64f_A53          ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Acosh
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAcosh_32f_A11         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAcosh_32f_A21         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAcosh_32f_A24         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAcosh_64f_A50         ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsAcosh_64f_A53         ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Asinh
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAsinh_32f_A11         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAsinh_32f_A21         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAsinh_32f_A24         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAsinh_64f_A50         ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsAsinh_64f_A53         ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Atanh
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsAtanh_32f_A11         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtanh_32f_A21         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtanh_32f_A24         ( const Fw32f *pSrc, Fw32f *pDst, int len );
FwStatus STDCALL fwsAtanh_64f_A50         ( const Fw64f *pSrc, Fw64f *pDst, int len );
FwStatus STDCALL fwsAtanh_64f_A53         ( const Fw64f *pSrc, Fw64f *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Copy
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsCopy_8u               ( const Fw8u   *pSrc, Fw8u   *pDst, int len );
FwStatus STDCALL fwsCopy_16s              ( const Fw16s  *pSrc, Fw16s  *pDst, int len );
FwStatus STDCALL fwsCopy_32f              ( const Fw32f  *pSrc, Fw32f  *pDst, int len );
FwStatus STDCALL fwsCopy_64f              ( const Fw64f  *pSrc, Fw64f  *pDst, int len );
FwStatus STDCALL fwsCopy_16sc             ( const Fw16sc *pSrc, Fw16sc *pDst, int len );
FwStatus STDCALL fwsCopy_32fc             ( const Fw32fc *pSrc, Fw32fc *pDst, int len );
FwStatus STDCALL fwsCopy_64fc             ( const Fw64fc *pSrc, Fw64fc *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Move
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsMove_8u               ( const Fw8u   *pSrc, Fw8u   *pDst, int len );
FwStatus STDCALL fwsMove_16s              ( const Fw16s  *pSrc, Fw16s  *pDst, int len );
FwStatus STDCALL fwsMove_32f              ( const Fw32f  *pSrc, Fw32f  *pDst, int len );
FwStatus STDCALL fwsMove_64f              ( const Fw64f  *pSrc, Fw64f  *pDst, int len );
FwStatus STDCALL fwsMove_16sc             ( const Fw16sc *pSrc, Fw16sc *pDst, int len );
FwStatus STDCALL fwsMove_32fc             ( const Fw32fc *pSrc, Fw32fc *pDst, int len );
FwStatus STDCALL fwsMove_64fc             ( const Fw64fc *pSrc, Fw64fc *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Set
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsSet_8u                ( Fw8u   val, Fw8u   *pDst, int len );
FwStatus STDCALL fwsSet_16s               ( Fw16s  val, Fw16s  *pDst, int len );
FwStatus STDCALL fwsSet_32s               ( Fw32s  val, Fw32s  *pDst, int len );
FwStatus STDCALL fwsSet_32f               ( Fw32f  val, Fw32f  *pDst, int len );
FwStatus STDCALL fwsSet_64s               ( Fw64s  val, Fw64s  *pDst, int len );
FwStatus STDCALL fwsSet_64f               ( Fw64f  val, Fw64f  *pDst, int len );
FwStatus STDCALL fwsSet_16sc              ( Fw16sc val, Fw16sc *pDst, int len );
FwStatus STDCALL fwsSet_32sc              ( Fw32sc val, Fw32sc *pDst, int len );
FwStatus STDCALL fwsSet_32fc              ( Fw32fc val, Fw32fc *pDst, int len );
FwStatus STDCALL fwsSet_64sc              ( Fw64sc val, Fw64sc *pDst, int len );
FwStatus STDCALL fwsSet_64fc              ( Fw64fc val, Fw64fc *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Zero
////////////////////////////////////////////////////////////////

FwStatus STDCALL fwsZero_8u               ( Fw8u   *pDst, int len );
FwStatus STDCALL fwsZero_16s              ( Fw16s  *pDst, int len );
FwStatus STDCALL fwsZero_32f              ( Fw32f  *pDst, int len );
FwStatus STDCALL fwsZero_64f              ( Fw64f  *pDst, int len );
FwStatus STDCALL fwsZero_16sc             ( Fw16sc *pDst, int len );
FwStatus STDCALL fwsZero_32fc             ( Fw32fc *pDst, int len );

////////////////////////////////////////////////////////////////
//                        Find
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsFind_8u(const Fw8u* pSrc, int len, const Fw8u* pFind, int lenFind, int* pIndex);
FwStatus STDCALL fwsFind_16u(const Fw16u* pSrc, int len, const Fw16u* pFind, int lenFind, int* pIndex);
FwStatus STDCALL fwsFindRev_8u(const Fw8u* pSrc, int len, const Fw8u* pFind, int lenFind, int* pIndex);
FwStatus STDCALL fwsFindRev_16u(const Fw16u* pSrc, int len, const Fw16u* pFind, int lenFind, int* pIndex);

////////////////////////////////////////////////////////////////
//                        Find
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsFindC_8u(const Fw8u* pSrc, int len, Fw8u valFind, int* pIndex);
FwStatus STDCALL fwsFindC_16u(const Fw16u* pSrc, int len, Fw16u valFind, int* pIndex);
FwStatus STDCALL fwsFindRevC_8u(const Fw8u* pSrc, int len, Fw8u valFind, int* pIndex);
FwStatus STDCALL fwsFindRevC_16u(const Fw16u* pSrc, int len, Fw16u valFind, int* pIndex);

////////////////////////////////////////////////////////////////
//                        Autocorrelation
////////////////////////////////////////////////////////////////


FwStatus STDCALL fwsAutoCorr_32f(const Fw32f* pSrc, int srcLen, Fw32f* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormA_32f(const Fw32f* pSrc, int srcLen, Fw32f* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormB_32f(const Fw32f* pSrc, int srcLen, Fw32f* pDst, int dstLen);

FwStatus STDCALL fwsAutoCorr_32fc(const Fw32fc* pSrc, int srcLen, Fw32fc* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormA_32fc(const Fw32fc* pSrc, int srcLen, Fw32fc* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormB_32fc(const Fw32fc* pSrc, int srcLen, Fw32fc* pDst, int dstLen);

FwStatus STDCALL fwsAutoCorr_64f(const Fw64f* pSrc, int srcLen, Fw64f* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormA_64f(const Fw64f* pSrc, int srcLen, Fw64f* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormB_64f(const Fw64f* pSrc, int srcLen, Fw64f* pDst, int dstLen);

FwStatus STDCALL fwsAutoCorr_64fc(const Fw64fc* pSrc, int srcLen, Fw64fc* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormA_64fc(const Fw64fc* pSrc, int srcLen, Fw64fc* pDst, int dstLen);
FwStatus STDCALL fwsAutoCorr_NormB_64fc(const Fw64fc* pSrc, int srcLen, Fw64fc* pDst, int dstLen);

////////////////////////////////////////////////////////////////
//                        fwsMalloc
////////////////////////////////////////////////////////////////

Fw8u*   STDCALL fwsMalloc_8u(int len);
Fw16u*  STDCALL fwsMalloc_16u(int len);
Fw32u*  STDCALL fwsMalloc_32u(int len);
Fw8s*   STDCALL fwsMalloc_8s(int len);
Fw16s*  STDCALL fwsMalloc_16s(int len);
Fw32s*  STDCALL fwsMalloc_32s(int len);
Fw64s*  STDCALL fwsMalloc_64s(int len);
Fw32f*  STDCALL fwsMalloc_32f(int len);
Fw64f*  STDCALL fwsMalloc_64f(int len);
Fw16sc* STDCALL fwsMalloc_16sc(int len);
Fw32sc* STDCALL fwsMalloc_32sc(int len);
Fw64sc* STDCALL fwsMalloc_64sc(int len);
Fw32fc* STDCALL fwsMalloc_32fc(int len);
Fw64fc* STDCALL fwsMalloc_64fc(int len);

////////////////////////////////////////////////////////////////
//                        fwsFree
////////////////////////////////////////////////////////////////

void STDCALL fwsFree(void* ptr);

#ifdef __cplusplus
}
#endif


#endif // __FWSIGNAL_H__
