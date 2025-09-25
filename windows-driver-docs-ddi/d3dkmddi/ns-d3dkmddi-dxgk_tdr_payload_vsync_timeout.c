typedef struct _DXGK_TDR_PAYLOAD_VSYNC_TIMEOUT {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  UINT                           LayerIndex;
  ULONGLONG                      PresentId;
} DXGK_TDR_PAYLOAD_VSYNC_TIMEOUT;