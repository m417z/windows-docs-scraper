typedef struct DXGI_FRAME_STATISTICS_MEDIA {
  UINT                         PresentCount;
  UINT                         PresentRefreshCount;
  UINT                         SyncRefreshCount;
  LARGE_INTEGER                SyncQPCTime;
  LARGE_INTEGER                SyncGPUTime;
  DXGI_FRAME_PRESENTATION_MODE CompositionMode;
  UINT                         ApprovedPresentDuration;
} DXGI_FRAME_STATISTICS_MEDIA;