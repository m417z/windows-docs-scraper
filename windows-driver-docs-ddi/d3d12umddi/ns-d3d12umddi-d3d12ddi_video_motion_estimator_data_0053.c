typedef struct D3D12DDI_VIDEO_MOTION_ESTIMATOR_DATA_0053 {
  UINT                                                          NodeIndex;
  DXGI_FORMAT                                                   InputFormat;
  D3D12DDI_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAGS_0053  BlockSizeFlags;
  D3D12DDI_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAGS_0053   PrecisionFlags;
  D3D12DDI_VIDEO_MOTION_ESTIMATOR_DIFFERENCES_METRIC_FLAGS_0053 DifferencesMetricFlags;
  D3D12DDI_VIDEO_SIZE_RANGE_0032                                SizeRange;
} D3D12DDI_VIDEO_MOTION_ESTIMATOR_DATA_0053;