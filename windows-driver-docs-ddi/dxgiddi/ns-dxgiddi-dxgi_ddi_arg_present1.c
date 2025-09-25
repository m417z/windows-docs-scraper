typedef struct DXGI_DDI_ARG_PRESENT1 {
  [in] DXGI_DDI_HDEVICE                  hDevice;
  [in] const DXGI_DDI_ARG_PRESENTSURFACE *phSurfacesToPresent;
  [in] UINT                              SurfacesToPresent;
  [in] DXGI_DDI_HRESOURCE                hDstResource;
  [in] UINT                              DstSubResourceIndex;
  [in] void                              *pDXGIContext;
  [in] DXGI_DDI_PRESENT_FLAGS            Flags;
  [in] DXGI_DDI_FLIP_INTERVAL_TYPE       FlipInterval;
       UINT                              Reserved;
  [in] const RECT                        *pDirtyRects;
  [in] UINT                              DirtyRects;
       UINT                              BackBufferMultiplicity;
} DXGI_DDI_ARG_PRESENT1;