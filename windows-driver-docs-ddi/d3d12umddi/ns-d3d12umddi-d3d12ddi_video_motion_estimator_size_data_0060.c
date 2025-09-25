typedef struct D3D12DDI_VIDEO_MOTION_ESTIMATOR_SIZE_DATA_0060 {
  UINT                                                   NodeMask;
  DXGI_FORMAT                                            InputFormat;
  D3D12DDI_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_0053 BlockSize;
  D3D12DDI_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_0053  Precision;
  D3D12DDI_VIDEO_SIZE_RANGE_0032                         SizeRange;
  BOOL                                                   Protected;
  UINT64                                                 MotionEstimatorMemoryPoolL0Size;
  UINT64                                                 MotionEstimatorMemoryPoolL1Size;
  UINT64                                                 MotionVectorHeapMemoryPoolL0Size;
  UINT64                                                 MotionVectorHeapMemoryPoolL1Size;
} D3D12DDI_VIDEO_MOTION_ESTIMATOR_SIZE_DATA_0060;