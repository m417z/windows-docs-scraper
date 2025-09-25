typedef struct D3DDDIARG_PRESENTMULTIPLANEOVERLAY {
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID    VidPnSourceId;
  [in] D3DDDI_PRESENTFLAGS               Flags;
  [in] D3DDDI_FLIPINTERVAL_TYPE          FlipInterval;
  [in] UINT                              PresentPlaneCount;
  [in] D3DDDI_PRESENT_MULTIPLANE_OVERLAY *pPresentPlanes;
  [in] UINT                              Reserved;
} D3DDDIARG_PRESENTMULTIPLANEOVERLAY;