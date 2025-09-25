typedef struct _DXGKARG_UPDATEFLIPQUEUELOG {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  UINT                           LayerIndex;
  ULONG                          FirstFreeFlipQueueLogEntryIndex;
} DXGKARG_UPDATEFLIPQUEUELOG;