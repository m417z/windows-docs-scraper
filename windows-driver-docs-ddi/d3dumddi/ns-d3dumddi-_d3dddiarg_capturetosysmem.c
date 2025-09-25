typedef struct _D3DDDIARG_CAPTURETOSYSMEM {
  [in] HANDLE hSrcResource;
  [in] RECT   SrcRect;
  [in] HANDLE hDstResource;
  [in] UINT   DstSubResourceIndex;
  [in] RECT   DstRect;
} D3DDDIARG_CAPTURETOSYSMEM;