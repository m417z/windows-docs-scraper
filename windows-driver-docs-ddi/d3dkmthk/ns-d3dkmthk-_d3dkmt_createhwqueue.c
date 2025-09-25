typedef struct _D3DKMT_CREATEHWQUEUE {
  D3DKMT_HANDLE                         hHwContext;
  D3DDDI_CREATEHWQUEUEFLAGS             Flags;
  UINT                                  PrivateDriverDataSize;
  VOID                                  *pPrivateDriverData;
  D3DKMT_HANDLE                         hHwQueue;
  D3DKMT_HANDLE                         hHwQueueProgressFence;
  VOID                                  *HwQueueProgressFenceCPUVirtualAddress;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS HwQueueProgressFenceGPUVirtualAddress;
} D3DKMT_CREATEHWQUEUE;