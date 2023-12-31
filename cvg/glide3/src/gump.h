/*
** THIS SOFTWARE IS SUBJECT TO COPYRIGHT PROTECTION AND IS OFFERED ONLY
** PURSUANT TO THE 3DFX GLIDE GENERAL PUBLIC LICENSE. THERE IS NO RIGHT
** TO USE THE GLIDE TRADEMARK WITHOUT PRIOR WRITTEN PERMISSION OF 3DFX
** INTERACTIVE, INC. A COPY OF THIS LICENSE MAY BE OBTAINED FROM THE 
** DISTRIBUTOR OR BY CONTACTING 3DFX INTERACTIVE INC(info@3dfx.com). 
** THIS PROGRAM IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER 
** EXPRESSED OR IMPLIED. SEE THE 3DFX GLIDE GENERAL PUBLIC LICENSE FOR A
** FULL TEXT OF THE NON-WARRANTY PROVISIONS.  
** 
** USE, DUPLICATION OR DISCLOSURE BY THE GOVERNMENT IS SUBJECT TO
** RESTRICTIONS AS SET FORTH IN SUBDIVISION (C)(1)(II) OF THE RIGHTS IN
** TECHNICAL DATA AND COMPUTER SOFTWARE CLAUSE AT DFARS 252.227-7013,
** AND/OR IN SIMILAR OR SUCCESSOR CLAUSES IN THE FAR, DOD OR NASA FAR
** SUPPLEMENT. UNPUBLISHED RIGHTS RESERVED UNDER THE COPYRIGHT LAWS OF
** THE UNITED STATES.  
** 
** COPYRIGHT 3DFX INTERACTIVE, INC. 1999, ALL RIGHTS RESERVED
**
** $Header$
** $Log$
** 
** 1     10/08/98 11:30a Brent
** 
** 3     7/24/98 1:41p Hohn
** 
** 2     1/26/98 11:30a Atai
** update to new glide.h
 * 
 * 1     1/16/98 4:29p Atai
 * create glide 3 src
**
*/

/* Multipass drawing */

#ifndef __GUMP_H__
#define __GUMP_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLIDE3_ALPHA
#define GLIDE_NUM_VIRTUAL_TMU   2   /* Number of virtual TMUs */

typedef FxU32 GrMPTextureCombineFnc_t;
#define GR_MPTEXTURECOMBINE_ADD           0x0 /*  */
#define GR_MPTEXTURECOMBINE_MULTIPLY      0x1 /*  */
#define GR_MPTEXTURECOMBINE_DETAIL0       0x2 /*  */
#define GR_MPTEXTURECOMBINE_DETAIL1       0x3 /*  */
#define GR_MPTEXTURECOMBINE_TRILINEAR0    0x4 /*  */
#define GR_MPTEXTURECOMBINE_TRILINEAR1    0x5 /*  */
#define GR_MPTEXTURECOMBINE_SUBTRACT      0x6 /*  */

typedef struct {
  GrMipMapId_t              mmid[GLIDE_NUM_VIRTUAL_TMU];
  GrMPTextureCombineFnc_t   tc_fnc;
} GrMPState;

FX_ENTRY void FX_CALL guMPInit( void );
FX_ENTRY void FX_CALL guMPTexCombineFunction( GrMPTextureCombineFnc_t tc );
FX_ENTRY void FX_CALL guMPTexSource( GrChipID_t virtual_tmu, GrMipMapId_t mmid );
FX_ENTRY void FX_CALL guMPDrawTriangle( const GrVertex *a, const GrVertex *b, const GrVertex *c );
#endif /* GLIDE3_ALPHA */

#ifdef __cplusplus
}
#endif

#endif /* __GUMP_H__ */
