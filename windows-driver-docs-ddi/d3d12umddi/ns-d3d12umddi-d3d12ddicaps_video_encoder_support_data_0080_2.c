typedef struct D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0080_2 {
  UINT                                                      NodeIndex;
  D3D12DDI_VIDEO_ENCODER_CODEC_0080                         Codec;
  D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2                TargetProfile;
  D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2               TargetLevel;
  DXGI_FORMAT                                               InputFormat;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0080_2         CodecConfiguration;
  D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2                RateControl;
  D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_MODE_0080            IntraRefresh;
  D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080   SubregionFrameEncoding;
  UINT                                                      ResolutionsListCount;
  const D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080 *pResolutionList;
  D3D12DDI_VIDEO_ENCODER_VALIDATION_FLAGS_0080              ValidationFlags;
  D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0080                 SupportFlags;
  D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2                SuggestedProfile;
  D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2               SuggestedLevel;
  D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2   *pResolutionDependentSupport;
} D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0080_2;