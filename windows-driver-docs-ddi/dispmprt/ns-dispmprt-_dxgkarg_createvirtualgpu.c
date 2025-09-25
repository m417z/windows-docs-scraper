typedef struct _DXGKARG_CREATEVIRTUALGPU {
  ULONG                      PartitionId;
  DXGK_VIRTUALGPUPROFILE     Profile;
  CLSID                      UserModeVirtualDeviceProvider;
  LUID                       VirtualGpuLuid;
  ULONG                      NumMemorySegments;
  DXGK_VIRTUALGPUSEGMENTINFO SegmentInfo[DXGK_MAX_VIRTUAL_GPU_ALLOCATIONS];
  ULONG                      NumEngines;
  DXGK_VIRTUALGPUENGINEINFO  EngineInfo[DXGK_MAX_ASYMETRICAL_PROCESSING_NODES];
} DXGKARG_CREATEVIRTUALGPU, *PDXGKARG_CREATEVIRTUALGPU;