typedef struct D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS {
  D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC SequenceControlDesc;
  D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC  PictureControlDesc;
  ID3D12Resource                            *pInputFrame;
  UINT                                      InputFrameSubresource;
  UINT                                      CurrentFrameBitstreamMetadataSize;
} D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS;