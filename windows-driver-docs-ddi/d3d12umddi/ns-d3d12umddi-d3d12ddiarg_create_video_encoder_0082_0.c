typedef struct D3D12DDIARG_CREATE_VIDEO_ENCODER_0082_0 {
  UINT                                                         NodeMask;
  D3D12DDI_VIDEO_ENCODER_FLAGS_0080                            Flags;
  D3D12DDI_VIDEO_ENCODER_CODEC_0080                            EncodeCodec;
  D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2                   EncodeProfile;
  DXGI_FORMAT                                                  InputFormat;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0            CodecConfiguration;
  D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080 MaxMotionEstimationPrecision;
} D3D12DDIARG_CREATE_VIDEO_ENCODER_0082_0;