typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS {
  UINT                                        NodeIndex;
  D3D12_VIDEO_ENCODER_CODEC                   Codec;
  D3D12_VIDEO_ENCODER_PROFILE_DESC            Profile;
  DXGI_FORMAT                                 InputFormat;
  D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC PictureTargetResolution;
  BOOL                                        IsSupported;
  UINT                                        CompressedBitstreamBufferAccessAlignment;
  UINT                                        EncoderMetadataBufferAccessAlignment;
  UINT                                        MaxEncoderOutputMetadataBufferSize;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS;