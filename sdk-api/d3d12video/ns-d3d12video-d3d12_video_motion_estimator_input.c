typedef struct D3D12_VIDEO_MOTION_ESTIMATOR_INPUT {
  ID3D12Resource              *pInputTexture2D;
  UINT                        InputSubresourceIndex;
  ID3D12Resource              *pReferenceTexture2D;
  UINT                        ReferenceSubresourceIndex;
  ID3D12VideoMotionVectorHeap *pHintMotionVectorHeap;
} D3D12_VIDEO_MOTION_ESTIMATOR_INPUT;