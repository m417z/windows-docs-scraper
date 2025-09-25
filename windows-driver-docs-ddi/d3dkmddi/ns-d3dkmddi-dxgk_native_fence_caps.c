typedef struct _DXGK_NATIVE_FENCE_CAPS {
  UINT                   MonitoredValueStride;
  BOOLEAN                MapToGpuSystemProcess;
  D3DGPU_VIRTUAL_ADDRESS MinimumAddress;
  D3DGPU_VIRTUAL_ADDRESS MaximumAddress;
  BYTE                   Reserved[28];
} DXGK_NATIVE_FENCE_CAPS;