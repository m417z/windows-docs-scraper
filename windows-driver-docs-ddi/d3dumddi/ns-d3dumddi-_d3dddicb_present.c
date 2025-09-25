typedef struct _D3DDDICB_PRESENT {
  [in] D3DKMT_HANDLE            hSrcAllocation;
  [in] D3DKMT_HANDLE            hDstAllocation;
  [in] HANDLE                   hContext;
  [in] UINT                     BroadcastContextCount;
       HANDLE                   BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
       D3DKMT_HANDLE            *BroadcastSrcAllocation;
       D3DKMT_HANDLE            *BroadcastDstAllocation;
       UINT                     PrivateDriverDataSize;
       PVOID                    pPrivateDriverData;
       BOOLEAN                  bOptimizeForComposition;
       BOOL                     SyncIntervalOverrideValid;
       D3DDDI_FLIPINTERVAL_TYPE SyncIntervalOverride;
} D3DDDICB_PRESENT;