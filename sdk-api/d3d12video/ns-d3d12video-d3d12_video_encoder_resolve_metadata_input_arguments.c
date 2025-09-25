typedef struct D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS {
  D3D12_VIDEO_ENCODER_CODEC                            EncoderCodec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC                     EncoderProfile;
  DXGI_FORMAT                                          EncoderInputFormat;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC          EncodedPictureEffectiveResolution;
  D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER HWLayoutMetadata;
} D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS;