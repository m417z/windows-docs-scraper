typedef struct _D3DKMT_SETQUEUEDLIMIT {
  [in]     D3DKMT_HANDLE           hDevice;
  [in]     D3DKMT_QUEUEDLIMIT_TYPE Type;
  union {
    [in/out] UINT QueuedPresentLimit;
    struct {
      D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
      UINT                           QueuedPendingFlipLimit;
    };
  };
} D3DKMT_SETQUEUEDLIMIT;