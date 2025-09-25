typedef struct D3D12DDICAPS_VIDEO_ENCODER_OUTPUT_RESOLUTION_DATA_0080_2 {
  UINT                                                      NodeIndex;
  D3D12DDI_VIDEO_ENCODER_CODEC_0080                         Codec;
  UINT                                                      ResolutionRatiosCount;
  BOOL                                                      IsSupported;
  D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080       MinResolutionSupported;
  D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080       MaxResolutionSupported;
  UINT                                                      ResolutionWidthMultipleRequirement;
  UINT                                                      ResolutionHeightMultipleRequirement;
  D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_RATIO_DESC_0080 *pResolutionRatios;
} D3D12DDICAPS_VIDEO_ENCODER_OUTPUT_RESOLUTION_DATA_0080_2;