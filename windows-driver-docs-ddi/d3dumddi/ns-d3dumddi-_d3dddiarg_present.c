typedef struct _D3DDDIARG_PRESENT {
  [in] HANDLE                   hSrcResource;
  [in] UINT                     SrcSubResourceIndex;
  [in] HANDLE                   hDstResource;
       UINT                     DstSubResourceIndex;
  [in] D3DDDI_PRESENTFLAGS      Flags;
  [in] D3DDDI_FLIPINTERVAL_TYPE FlipInterval;
} D3DDDIARG_PRESENT;