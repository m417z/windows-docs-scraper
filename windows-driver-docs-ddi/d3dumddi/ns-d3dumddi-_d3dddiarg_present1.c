typedef struct _D3DDDIARG_PRESENT1 {
  [in] const D3DDDIARG_PRESENTSURFACE *phSrcResources;
  [in] UINT                           SrcResources;
  [in] HANDLE                         hDstResource;
       UINT                           DstSubResourceIndex;
  [in] D3DDDI_PRESENTFLAGS            Flags;
  [in] D3DDDI_FLIPINTERVAL_TYPE       FlipInterval;
       UINT                           Reserved;
  [in] const RECT                     *pDirtyRects;
  [in] UINT                           DirtyRects;
       UINT                           BackBufferMultiplicity;
} D3DDDIARG_PRESENT1;