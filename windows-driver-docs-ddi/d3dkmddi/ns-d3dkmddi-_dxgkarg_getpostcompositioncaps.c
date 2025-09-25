typedef struct _DXGKARG_GETPOSTCOMPOSITIONCAPS {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] float                          MaxStretchFactor;
  [out] float                          MaxShrinkFactor;
} DXGKARG_GETPOSTCOMPOSITIONCAPS;