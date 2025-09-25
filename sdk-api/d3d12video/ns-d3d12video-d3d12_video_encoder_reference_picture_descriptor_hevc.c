typedef struct D3D12_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_HEVC {
  UINT ReconstructedPictureResourceIndex;
  BOOL IsRefUsedByCurrentPic;
  BOOL IsLongTermReference;
  UINT PictureOrderCountNumber;
  UINT TemporalLayerIndex;
} D3D12_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_HEVC;