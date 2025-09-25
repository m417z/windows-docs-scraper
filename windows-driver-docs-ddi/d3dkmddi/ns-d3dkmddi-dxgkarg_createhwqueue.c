typedef struct _DXGKARG_CREATEHWQUEUE {
  HANDLE                    hHwQueue;
  D3DDDI_CREATEHWQUEUEFLAGS Flags;
  UINT                      PrivateDriverDataSize;
  VOID                      *pPrivateDriverData;
  D3DKMT_HANDLE             hHwQueueProgressFence;
  VOID                      *HwQueueProgressFenceCPUVirtualAddress;
  D3DGPU_VIRTUAL_ADDRESS    HwQueueProgressFenceGPUVirtualAddress;
} DXGKARG_CREATEHWQUEUE;