typedef struct _DXGK_NATIVE_FENCE_LOG_ENTRY {
  UINT64        FenceValue;
  D3DKMT_HANDLE hNativeFence;
  UINT          OperationType;
  UINT64        Reserved0;
  UINT64        FenceObservedGpuTimestamp;
  UINT64        Reserved1;
  UINT64        FenceEndGpuTimestamp;
} DXGK_NATIVE_FENCE_LOG_ENTRY;