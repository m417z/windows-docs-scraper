typedef struct _DXGK_VIDMMCAPS {
  union {
    struct {
      UINT OutOfOrderLock : 1;
      UINT DedicatedPagingEngine : 1;
      UINT PagingEngineCanSwizzle : 1;
      UINT SectionBackedPrimary : 1;
      UINT CrossAdapterResource : 1;
      UINT VirtualAddressingSupported : 1;
      UINT GpuMmuSupported : 1;
      UINT IoMmuSupported : 1;
      UINT ReplicateGdiContent : 1;
      UINT NonCpuVisiblePrimary : 1;
      UINT ParavirtualizationSupported : 1;
      UINT IoMmuSecureModeSupported : 1;
      UINT DisableSelfRefreshVRAMInS3 : 1;
      UINT IoMmuSecureModeRequired : 1;
      UINT MapAperture2Supported : 1;
      UINT CrossAdapterResourceTexture : 1;
      UINT CrossAdapterResourceScanout : 1;
      UINT AlwaysPoweredVRAM : 1;
#if ...
      UINT Reserved : 14;
#elif
      UINT Reserved : 15;
#elif
      UINT Reserved : 18;
#elif
      UINT Reserved : 19;
#elif
      UINT Reserved : 21;
#elif
      UINT Reserved : 22;
#elif
      UINT Reserved : 27;
#elif
      UINT Reserved : 28;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
  UINT  PagingNode;
} DXGK_VIDMMCAPS;