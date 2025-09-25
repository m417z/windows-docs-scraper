typedef struct _DXGK_GDIARG_ALPHABLEND {
  [in] RECT    SrcRect;
  [in] RECT    DstRect;
  [in] UINT    SrcAllocationIndex;
  [in] UINT    DstAllocationIndex;
  [in] UINT    NumSubRects;
  [in] RECT    *pSubRects;
  [in] BYTE    SourceConstantAlpha;
  [in] BOOLEAN SourceHasAlpha;
  [in] UINT    SrcPitch;
} DXGK_GDIARG_ALPHABLEND;