typedef struct D3D12DDIARG_PRESENT_0001 {
  const D3D12DDI_ARG_PRESENTSURFACE *phSurfacesToPresent;
  UINT                              SurfacesToPresent;
  D3D12DDI_HRESOURCE                hDstResource;
  UINT                              DstSubResourceIndex;
  DXGI_DDI_PRESENT_FLAGS            Flags;
  DXGI_DDI_FLIP_INTERVAL_TYPE       FlipInterval;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID    VidPnSourceID;
  const RECT                        *pDirtyRects;
  UINT                              DirtyRects;
  UINT                              PrivateDriverDataSize;
  VOID                              *pPrivateDriverData;
  BOOL                              OptimizeForComposition;
} D3D12DDIARG_PRESENT_0001;