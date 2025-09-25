typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_INPUT_FORMAT {
  UINT                             NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC        Codec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC Profile;
  DXGI_FORMAT                      Format;
  BOOL                             IsSupported;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_INPUT_FORMAT;