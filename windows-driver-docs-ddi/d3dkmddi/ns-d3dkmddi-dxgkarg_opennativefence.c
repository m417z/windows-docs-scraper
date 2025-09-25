typedef struct _DXGKARG_OPENNATIVEFENCE {
  HANDLE                     hGlobalNativeFence;
  HANDLE                     hLocalNativeFence;
  HANDLE                     hDevice;
  D3DGPU_VIRTUAL_ADDRESS     CurrentValueGpuVa;
  D3DGPU_VIRTUAL_ADDRESS     MonitoredValueGpuVa;
  DXGK_OPENNATIVEFENCE_FLAGS Flags;
  BYTE                       pPrivateDriverData[D3DDDI_NATIVE_FENCE_PDD_SIZE];
  BYTE                       Reserved[32];
} DXGKARG_OPENNATIVEFENCE;