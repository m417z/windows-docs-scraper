typedef struct _DXGKARG_CREATENATIVEFENCE {
  HANDLE                          hGlobalNativeFence;
  D3DDDI_NATIVEFENCE_TYPE         Type;
  D3DGPU_VIRTUAL_ADDRESS          CurrentValueSystemProcessGpuVa;
  D3DGPU_VIRTUAL_ADDRESS          MonitoredValueSystemProcessGpuVa;
  BYTE                            pPrivateDriverData[D3DDDI_NATIVE_FENCE_PDD_SIZE];
  DXGKARG_CREATENATIVEFENCE_FLAGS Flags;
  BYTE                            Reserved[32];
} DXGKARG_CREATENATIVEFENCE;