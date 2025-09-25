typedef struct D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_DESCRIPTOR_0095 {
  UINT                                                                 ReconstructedPictureResourceIndex;
  UINT                                                                 TemporalLayerIndexPlus1;
  UINT                                                                 SpatialLayerIndexPlus1;
  D3D12DDI_VIDEO_ENCODER_AV1_FRAME_TYPE_0095                           FrameType;
  D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095 WarpedMotionInfo;
  UINT                                                                 OrderHint;
  UINT                                                                 PictureIndex;
} D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_DESCRIPTOR_0095;