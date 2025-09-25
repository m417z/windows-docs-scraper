typedef struct D3D12DDI_ALLOCATION_INFO_0022 {
  D3DKMT_HANDLE                       hAllocation;
  const VOID                          *pSystemMem;
  VOID                                *pPrivateDriverData;
  UINT                                PrivateDriverDataSize;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID      VidPnSourceId;
  D3D12DDI_ALLOCATION_INFO_FLAGS_0022 Flags;
  D3DGPU_VIRTUAL_ADDRESS              GpuVirtualAddress;
  UINT                                Priority;
  ULONG_PTR                           Reserved[5];
} D3D12DDI_ALLOCATION_INFO_0022;