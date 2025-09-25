typedef struct D3D12DDICAPS_VIDEO_ENCODER_RESOURCE_REQUIREMENTS_DATA_0080_2 {
  UINT                                                NodeIndex;
  D3D12DDI_VIDEO_ENCODER_CODEC_0080                   Codec;
  D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2          Profile;
  DXGI_FORMAT                                         InputFormat;
  D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080 PictureTargetResolution;
  BOOL                                                IsSupported;
  UINT                                                CompressedBitstreamBufferAccessAlignment;
  UINT                                                EncoderMetadataBufferAccessAlignment;
  UINT                                                MaxEncoderOutputMetadataBufferSize;
} D3D12DDICAPS_VIDEO_ENCODER_RESOURCE_REQUIREMENTS_DATA_0080_2;