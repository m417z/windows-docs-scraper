typedef struct _D3DKMT_PRESENT_STATS_DWM {
  UINT                         PresentCount;
  UINT                         PresentRefreshCount;
  D3DKMT_ALIGN64 LARGE_INTEGER PresentQPCTime;
  UINT                         SyncRefreshCount;
  D3DKMT_ALIGN64 LARGE_INTEGER SyncQPCTime;
  UINT                         CustomPresentDuration;
} D3DKMT_PRESENT_STATS_DWM;