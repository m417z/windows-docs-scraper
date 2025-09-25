typedef struct _DXGKARG_GETMULTIPLANEOVERLAYCAPS {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] UINT                           MaxPlanes;
  [out] UINT                           MaxRGBPlanes;
  [out] UINT                           MaxYUVPlanes;
  [out] DXGK_MULTIPLANEOVERLAYCAPS     OverlayCaps;
  [out] float                          MaxStretchFactor;
  [out] float                          MaxShrinkFactor;
} DXGKARG_GETMULTIPLANEOVERLAYCAPS;