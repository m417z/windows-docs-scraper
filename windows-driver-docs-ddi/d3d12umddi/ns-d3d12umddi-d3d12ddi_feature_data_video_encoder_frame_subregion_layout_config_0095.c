typedef struct D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095 {
  UINT                                                              NodeIndex;
  D3D12DDI_VIDEO_ENCODER_CODEC_0080                                 Codec;
  D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2                        Profile;
  D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2                       Level;
  D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080           SubregionMode;
  D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080               FrameResolution;
  D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095 CodecSupport;
  BOOL                                                              IsSupported;
} D3D12DDI_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_CONFIG_0095;