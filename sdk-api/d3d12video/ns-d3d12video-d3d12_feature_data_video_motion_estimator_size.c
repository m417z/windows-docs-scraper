typedef struct D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR_SIZE {
  UINT                                           NodeIndex;
  DXGI_FORMAT                                    InputFormat;
  D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE BlockSize;
  D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION  Precision;
  D3D12_VIDEO_SIZE_RANGE                         SizeRange;
  BOOL                                           Protected;
  UINT64                                         MotionVectorHeapMemoryPoolL0Size;
  UINT64                                         MotionVectorHeapMemoryPoolL1Size;
  UINT64                                         MotionEstimatorMemoryPoolL0Size;
  UINT64                                         MotionEstimatorMemoryPoolL1Size;
} D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR_SIZE;