typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_OUTPUT_RESOLUTION {
  UINT                                              NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC                         Codec;
  UINT                                              ResolutionRatiosCount;
  BOOL                                              IsSupported;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC       MinResolutionSupported;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC       MaxResolutionSupported;
  UINT                                              ResolutionWidthMultipleRequirement;
  UINT                                              ResolutionHeightMultipleRequirement;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_RATIO_DESC *pResolutionRatios;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_OUTPUT_RESOLUTION;