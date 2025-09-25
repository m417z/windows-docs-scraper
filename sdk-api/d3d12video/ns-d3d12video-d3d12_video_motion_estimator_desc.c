typedef struct D3D12_VIDEO_MOTION_ESTIMATOR_DESC {
  UINT                                           NodeMask;
  DXGI_FORMAT                                    InputFormat;
  D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE BlockSize;
  D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION  Precision;
  D3D12_VIDEO_SIZE_RANGE                         SizeRange;
} D3D12_VIDEO_MOTION_ESTIMATOR_DESC;