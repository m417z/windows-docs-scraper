typedef struct _DXGKARG_SETNATIVEFENCELOGBUFFER {
  HANDLE                                hHwQueue;
  UINT                                  NumberOfEntries;
  DXGK_NATIVE_FENCE_LOG_BUFFER          *LogBufferCpuVa;
  D3DGPU_VIRTUAL_ADDRESS                LogBufferGpuVa;
  D3DGPU_VIRTUAL_ADDRESS                LogBufferSystemProcessGpuVa;
  DXGKARG_SETNATIVEFENCELOGBUFFER_FLAGS Flags;
  BYTE                                  Reserved[32];
} DXGKARG_SETNATIVEFENCELOGBUFFER;