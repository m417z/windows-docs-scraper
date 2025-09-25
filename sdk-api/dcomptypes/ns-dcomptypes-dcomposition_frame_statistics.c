typedef struct {
  LARGE_INTEGER lastFrameTime;
  DXGI_RATIONAL currentCompositionRate;
  LARGE_INTEGER currentTime;
  LARGE_INTEGER timeFrequency;
  LARGE_INTEGER nextEstimatedFrameTime;
} DCOMPOSITION_FRAME_STATISTICS;