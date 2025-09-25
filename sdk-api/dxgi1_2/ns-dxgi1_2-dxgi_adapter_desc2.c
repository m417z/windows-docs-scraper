typedef struct DXGI_ADAPTER_DESC2 {
  WCHAR                                Description[128];
  UINT                                 VendorId;
  UINT                                 DeviceId;
  UINT                                 SubSysId;
  UINT                                 Revision;
  SIZE_T                               DedicatedVideoMemory;
  SIZE_T                               DedicatedSystemMemory;
  SIZE_T                               SharedSystemMemory;
  LUID                                 AdapterLuid;
  UINT                                 Flags;
  DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity;
  DXGI_COMPUTE_PREEMPTION_GRANULARITY  ComputePreemptionGranularity;
} DXGI_ADAPTER_DESC2;