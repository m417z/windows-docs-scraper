typedef struct DXGI_FRAME_STATISTICS {
  UINT          PresentCount;
  UINT          PresentRefreshCount;
  UINT          SyncRefreshCount;
  LARGE_INTEGER SyncQPCTime;
  LARGE_INTEGER SyncGPUTime;
} DXGI_FRAME_STATISTICS;