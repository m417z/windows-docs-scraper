typedef struct _DXGK_GDIARG_TRANSPARENTBLT {
  [in] RECT                      SrcRect;
  [in] RECT                      DstRect;
       UINT                      SrcAllocationIndex;
       UINT                      DstAllocationIndex;
       UINT                      Color;
       UINT                      NumSubRects;
       RECT                      *pSubRects;
       D3DKM_TRANSPARENTBLTFLAGS Flags;
       UINT                      SrcPitch;
} DXGK_GDIARG_TRANSPARENTBLT;