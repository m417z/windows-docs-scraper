typedef struct DXGIDDICB_SUBMITPRESENTTOHWQUEUE {
  void                        *pDXGIContext;
  D3DKMT_HANDLE               *BroadcastSrcAllocations;
  D3DKMT_HANDLE               *BroadcastDstAllocations;
  HANDLE                      *hHwQueues;
  UINT                        BroadcastHwQueueCount;
  UINT                        PrivateDriverDataSize;
  PVOID                       pPrivateDriverData;
  BOOLEAN                     bOptimizeForComposition;
  BOOL                        SyncIntervalOverrideValid;
  DXGI_DDI_FLIP_INTERVAL_TYPE SyncIntervalOverride;
} DXGIDDICB_SUBMITPRESENTTOHWQUEUE;