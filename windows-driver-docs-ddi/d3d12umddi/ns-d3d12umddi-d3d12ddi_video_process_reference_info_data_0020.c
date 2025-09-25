typedef struct D3D12DDI_VIDEO_PROCESS_REFERENCE_INFO_DATA_0020 {
  UINT                                              NodeIndex;
  D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS_0020     DeinterlaceMode;
  D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS_0020          Filters;
  D3D12DDI_VIDEO_PROCESS_FEATURE_SUPPORT_FLAGS_0020 FeatureSupport;
  DXGI_RATIONAL                                     InputFrameRate;
  DXGI_RATIONAL                                     OutputFrameRate;
  BOOL                                              EnableAutoProcessing;
  UINT                                              PastFrames;
  UINT                                              FutureFrames;
} D3D12DDI_VIDEO_PROCESS_REFERENCE_INFO_DATA_0020;