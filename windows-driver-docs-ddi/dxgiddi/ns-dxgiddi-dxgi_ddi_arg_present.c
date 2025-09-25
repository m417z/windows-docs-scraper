typedef struct DXGI_DDI_ARG_PRESENT {
  [in] DXGI_DDI_HDEVICE            hDevice;
  [in] DXGI_DDI_HRESOURCE          hSurfaceToPresent;
  [in] UINT                        SrcSubResourceIndex;
  [in] DXGI_DDI_HRESOURCE          hDstResource;
       UINT                        DstSubResourceIndex;
  [in] void                        *pDXGIContext;
  [in] DXGI_DDI_PRESENT_FLAGS      Flags;
  [in] DXGI_DDI_FLIP_INTERVAL_TYPE FlipInterval;
} DXGI_DDI_ARG_PRESENT;