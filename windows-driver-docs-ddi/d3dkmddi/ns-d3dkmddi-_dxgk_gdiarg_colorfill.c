typedef struct _DXGK_GDIARG_COLORFILL {
  [in] RECT DstRect;
       UINT DstAllocationIndex;
       UINT NumSubRects;
       RECT *pSubRects;
       UINT Color;
       WORD Rop;
       WORD Rop3;
} DXGK_GDIARG_COLORFILL;