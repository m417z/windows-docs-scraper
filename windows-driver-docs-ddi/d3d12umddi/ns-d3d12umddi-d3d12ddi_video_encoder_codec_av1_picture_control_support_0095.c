typedef struct D3D12DDI_VIDEO_ENCODER_CODEC_AV1_PICTURE_CONTROL_SUPPORT_0095 {
  D3D12DDI_VIDEO_ENCODER_AV1_COMP_PREDICTION_TYPE_0095                         PredictionMode;
  UINT                                                                         MaxUniqueReferencesPerFrame;
  D3D12DDI_VIDEO_ENCODER_AV1_FRAME_TYPE_0095_FLAGS                             SupportedFrameTypes;
  D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAGS SupportedReferenceWarpedMotionFlags;
} D3D12DDI_VIDEO_ENCODER_CODEC_AV1_PICTURE_CONTROL_SUPPORT_0095;