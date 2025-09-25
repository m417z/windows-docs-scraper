typedef struct _DXGK_GDIARG_CLEARTYPEBLEND {
  [in] RECT DstRect;
       UINT TmpSurfAllocationIndex;
       UINT GammaSurfAllocationIndex;
       UINT AlphaSurfAllocationIndex;
       UINT DstAllocationIndex;
       INT  DstToAlphaOffsetX;
       INT  DstToAlphaOffsetY;
       UINT Color;
       UINT Gamma;
       UINT NumSubRects;
       RECT *pSubRects;
       UINT AlphaSurfPitch;
       UINT Color2;
} DXGK_GDIARG_CLEARTYPEBLEND;