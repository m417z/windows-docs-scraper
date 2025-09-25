typedef struct _D3DDDI_ALLOCATIONINFO2 {
  D3DKMT_HANDLE                         hAllocation;
  union {
    HANDLE     hSection;
    const VOID *pSystemMem;
  } D3DKMT_ALIGN64;
  VOID                                  *pPrivateDriverData;
  UINT                                  PrivateDriverDataSize;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID        VidPnSourceId;
  union {
    struct {
      UINT Primary : 1;
      UINT Stereo : 1;
      UINT OverridePriority : 1;
#if ...
      UINT Reserved : 29;
#elif
      UINT Reserved : 30;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  } Flags;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS GpuVirtualAddress;
  union {
    UINT                     Priority;
    D3DKMT_ALIGN64 ULONG_PTR Unused;
  };
#if ...
  D3DKMT_ALIGN64 ULONG_PTR              Reserved[5];
#else
  D3DKMT_ALIGN64 ULONG_PTR              Reserved[6];
#endif
} D3DDDI_ALLOCATIONINFO2;