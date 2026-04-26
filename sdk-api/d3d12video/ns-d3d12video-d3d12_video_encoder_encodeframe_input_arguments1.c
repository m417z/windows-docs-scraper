typedef struct D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS1 {
  D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC          SequenceControlDesc;
  D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC1          PictureControlDesc;
  ID3D12Resource                                     *pInputFrame;
  UINT                                               InputFrameSubresource;
  UINT                                               CurrentFrameBitstreamMetadataSize;
  D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAGS OptionalMetadata;
} D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS1;