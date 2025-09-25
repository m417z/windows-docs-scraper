typedef struct DXGIDDICB_PRESENT {
  [in] D3DKMT_HANDLE               hSrcAllocation;
  [in] D3DKMT_HANDLE               hDstAllocation;
  [in] void                        *pDXGIContext;
  [in] HANDLE                      hContext;
  [in] UINT                        BroadcastContextCount;
       HANDLE                      BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
       D3DKMT_HANDLE               *BroadcastSrcAllocation;
       D3DKMT_HANDLE               *BroadcastDstAllocation;
       UINT                        PrivateDriverDataSize;
       PVOID                       pPrivateDriverData;
       BOOLEAN                     bOptimizeForComposition;
       BOOL                        SyncIntervalOverrideValid;
       DXGI_DDI_FLIP_INTERVAL_TYPE SyncIntervalOverride;
} DXGIDDICB_PRESENT;