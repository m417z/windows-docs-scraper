typedef struct D3D12_VIDEO_ENCODER_DESC {
  UINT                                                 NodeMask;
  D3D12_VIDEO_ENCODER_FLAGS                            Flags;
  D3D12_VIDEO_ENCODER_CODEC                            EncodeCodec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                     EncodeProfile;
  DXGI_FORMAT                                          InputFormat;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION              CodecConfiguration;
  D3D12_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE MaxMotionEstimationPrecision;
} D3D12_VIDEO_ENCODER_DESC;