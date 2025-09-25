typedef struct _D3DKMT_DEVICE_ESCAPE {
        D3DKMT_DEVICEESCAPE_TYPE Type;
  union {
    struct {
      D3DKMT_HANDLE                  hPrimaryAllocation;
      D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
    } VidPnFromAllocation;
  };
} D3DKMT_DEVICE_ESCAPE;