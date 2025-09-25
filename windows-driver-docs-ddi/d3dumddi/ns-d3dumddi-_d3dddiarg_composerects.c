typedef struct _D3DDDIARG_COMPOSERECTS {
  [in] HANDLE                hSrcResource;
  [in] UINT                  SrcSubResourceIndex;
  [in] HANDLE                hDstResource;
  [in] UINT                  DstSubResourceIndex;
  [in] HANDLE                hSrcRectDescsVB;
  [in] UINT                  NumRects;
  [in] HANDLE                hDstRectDescsVB;
  [in] D3DDDI_COMPOSERECTSOP Operation;
  [in] INT                   XOffset;
  [in] INT                   YOffset;
} D3DDDIARG_COMPOSERECTS;