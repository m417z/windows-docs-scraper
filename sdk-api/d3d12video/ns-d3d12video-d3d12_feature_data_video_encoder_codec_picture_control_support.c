typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT {
  UINT                                              NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC                         Codec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                  Profile;
  BOOL                                              IsSupported;
  D3D12_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT PictureSupport;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT;