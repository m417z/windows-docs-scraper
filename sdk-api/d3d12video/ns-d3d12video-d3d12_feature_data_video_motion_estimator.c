typedef struct D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR {
  UINT                                                 NodeIndex;
  DXGI_FORMAT                                          InputFormat;
  D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAGS BlockSizeFlags;
  D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAGS  PrecisionFlags;
  D3D12_VIDEO_SIZE_RANGE                               SizeRange;
} D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR;