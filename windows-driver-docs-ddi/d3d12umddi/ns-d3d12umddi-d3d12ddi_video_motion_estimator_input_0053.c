typedef struct D3D12DDI_VIDEO_MOTION_ESTIMATOR_INPUT_0053 {
  D3D12DDI_HRESOURCE                   hDrvInputTexture2D;
  UINT                                 InputSubresourceIndex;
  D3D12DDI_HRESOURCE                   hDrvReferenceTexture2D;
  UINT                                 ReferenceSubresourceIndex;
  D3D12DDI_HVIDEOMOTIONVECTORHEAP_0053 hDrvPreviousMotionVectorHeap;
} D3D12DDI_VIDEO_MOTION_ESTIMATOR_INPUT_0053;