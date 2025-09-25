typedef struct D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0 {
  D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0 SequenceControlDesc;
  D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0  PictureControlDesc;
  D3D12DDI_HRESOURCE                                  hDrvInputTexture2D;
  UINT                                                InputFrameSubresource;
  UINT                                                CurrentFrameBitstreamMetadataSize;
} D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0;