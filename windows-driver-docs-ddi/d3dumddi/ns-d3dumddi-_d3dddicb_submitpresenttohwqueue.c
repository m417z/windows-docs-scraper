typedef struct _D3DDDICB_SUBMITPRESENTTOHWQUEUE {
  D3DKMT_HANDLE            *BroadcastSrcAllocations;
  D3DKMT_HANDLE            *BroadcastDstAllocations;
  HANDLE                   *hHwQueues;
  UINT                     BroadcastHwQueueCount;
  UINT                     PrivateDriverDataSize;
  PVOID                    pPrivateDriverData;
  BOOLEAN                  bOptimizeForComposition;
  BOOL                     SyncIntervalOverrideValid;
  D3DDDI_FLIPINTERVAL_TYPE SyncIntervalOverride;
} D3DDDICB_SUBMITPRESENTTOHWQUEUE;