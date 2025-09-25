typedef struct _DXGK_GDIARG_BITBLT {
  [in] RECT SrcRect;
  [in] RECT DstRect;
       UINT SrcAllocationIndex;
       UINT DstAllocationIndex;
       UINT NumSubRects;
       RECT *pSubRects;
       WORD Rop;
       WORD Rop3;
       UINT SrcPitch;
       UINT DstPitch;
} DXGK_GDIARG_BITBLT;