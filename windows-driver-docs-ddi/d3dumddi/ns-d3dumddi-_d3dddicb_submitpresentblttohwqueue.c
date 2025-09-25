typedef struct _D3DDDICB_SUBMITPRESENTBLTTOHWQUEUE {
  [in] D3DKMT_HANDLE hSrcAllocation;
  [in] D3DKMT_HANDLE hDstAllocation;
  [in] HANDLE        hHwQueue;
       UINT64        HwQueueProgressFenceId;
       UINT          PrivateDriverDataSize;
       PVOID         pPrivateDriverData;
} D3DDDICB_SUBMITPRESENTBLTTOHWQUEUE;