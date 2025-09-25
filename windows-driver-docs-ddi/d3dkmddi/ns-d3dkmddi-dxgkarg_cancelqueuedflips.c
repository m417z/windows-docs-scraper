typedef struct _DXGKARG_CANCELQUEUEDFLIPS {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  UINT                           LayerIndex;
  ULONGLONG                      PresentIdCancelRequested;
  ULONGLONG                      PresentIdCancelled;
} DXGKARG_CANCELQUEUEDFLIPS;