typedef struct _DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY {
  [in] DXGI_DDI_HDEVICE                    hDevice;
  [in] void                                *pDXGIContext;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID      VidPnSourceId;
  [in] DXGI_DDI_PRESENT_FLAGS              Flags;
  [in] DXGI_DDI_FLIP_INTERVAL_TYPE         FlipInterval;
  [in] UINT                                PresentPlaneCount;
  [in] DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY *pPresentPlanes;
       UINT                                Reserved;
} DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY;