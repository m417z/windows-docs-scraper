typedef struct _D3DKMT_PRESENT_STATS {
  [out] UINT                         PresentCount;
  [out] UINT                         PresentRefreshCount;
  [out] UINT                         SyncRefreshCount;
  [out] D3DKMT_ALIGN64 LARGE_INTEGER SyncQPCTime;
  [out] D3DKMT_ALIGN64 LARGE_INTEGER SyncGPUTime;
} D3DKMT_PRESENT_STATS;