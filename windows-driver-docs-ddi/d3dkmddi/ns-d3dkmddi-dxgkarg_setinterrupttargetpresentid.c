typedef struct _DXGKARG_SETINTERRUPTTARGETPRESENTID {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  UINT                           LayerIndex;
  ULONGLONG                      InterruptTargetPresentId;
} DXGKARG_SETINTERRUPTTARGETPRESENTID;