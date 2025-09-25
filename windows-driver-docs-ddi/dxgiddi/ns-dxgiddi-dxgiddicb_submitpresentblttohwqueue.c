typedef struct DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE {
  [in] D3DKMT_HANDLE hSrcAllocation;
  [in] D3DKMT_HANDLE hDstAllocation;
       void          *pDXGIContext;
       HANDLE        hHwQueue;
       UINT64        HwQueueProgressFenceId;
       UINT          PrivateDriverDataSize;
  [in] PVOID         pPrivateDriverData;
} DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE;