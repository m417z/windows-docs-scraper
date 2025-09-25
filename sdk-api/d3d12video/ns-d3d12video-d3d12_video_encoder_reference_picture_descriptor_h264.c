typedef struct D3D12_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_H264 {
  UINT ReconstructedPictureResourceIndex;
  BOOL IsLongTermReference;
  UINT LongTermPictureIdx;
  UINT PictureOrderCountNumber;
  UINT FrameDecodingOrderNumber;
  UINT TemporalLayerIndex;
} D3D12_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_H264;