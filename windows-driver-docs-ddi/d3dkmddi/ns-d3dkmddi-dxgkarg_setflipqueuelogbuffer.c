typedef struct _DXGKARG_SETFLIPQUEUELOGBUFFER {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  UINT                           LayerIndex;
  UINT                           NumberOfEntries;
  DXGK_FLIPQUEUE_LOG_ENTRY       *LogBufferAddress;
} DXGKARG_SETFLIPQUEUELOGBUFFER;