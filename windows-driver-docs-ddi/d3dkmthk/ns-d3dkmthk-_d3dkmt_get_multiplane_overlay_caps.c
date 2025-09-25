typedef struct _D3DKMT_GET_MULTIPLANE_OVERLAY_CAPS {
  [in]  D3DKMT_HANDLE                  hAdapter;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] UINT                           MaxPlanes;
  [out] UINT                           MaxRGBPlanes;
  [out] UINT                           MaxYUVPlanes;
  [out] D3DKMT_MULTIPLANE_OVERLAY_CAPS OverlayCaps;
  [out] float                          MaxStretchFactor;
  [out] float                          MaxShrinkFactor;
} D3DKMT_GET_MULTIPLANE_OVERLAY_CAPS;