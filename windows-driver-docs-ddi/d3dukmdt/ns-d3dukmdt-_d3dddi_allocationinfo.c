typedef struct _D3DDDI_ALLOCATIONINFO {
  D3DKMT_HANDLE                  hAllocation;
  const VOID                     *pSystemMem;
  VOID                           *pPrivateDriverData;
  UINT                           PrivateDriverDataSize;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  union {
    struct {
      UINT Primary : 1;
      UINT Stereo : 1;
#if ...
      UINT Reserved : 30;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  } Flags;
} D3DDDI_ALLOCATIONINFO;