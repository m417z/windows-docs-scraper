typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_RATE_CONTROL_MODE {
  UINT                                  NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC             Codec;
  D3D12_VIDEO_ENCODER_RATE_CONTROL_MODE RateControlMode;
  BOOL                                  IsSupported;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_RATE_CONTROL_MODE;