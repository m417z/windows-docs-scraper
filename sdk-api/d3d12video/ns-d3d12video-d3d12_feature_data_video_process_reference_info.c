typedef struct D3D12_FEATURE_DATA_VIDEO_PROCESS_REFERENCE_INFO {
  UINT                                  NodeIndex;
  D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS DeinterlaceMode;
  D3D12_VIDEO_PROCESS_FILTER_FLAGS      Filters;
  D3D12_VIDEO_PROCESS_FEATURE_FLAGS     FeatureSupport;
  DXGI_RATIONAL                         InputFrameRate;
  DXGI_RATIONAL                         OutputFrameRate;
  BOOL                                  EnableAutoProcessing;
  UINT                                  PastFrames;
  UINT                                  FutureFrames;
} D3D12_FEATURE_DATA_VIDEO_PROCESS_REFERENCE_INFO;