typedef struct D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_MOTION_VECTORS {
  D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_CONFIG   MotionSearchModeConfiguration;
  UINT                                                  NumHintsPerPixel;
  ID3D12Resource                                        **ppMotionVectorMaps;
  UINT                                                  *pMotionVectorMapsSubresources;
  ID3D12Resource                                        **ppMotionVectorMapsMetadata;
  UINT                                                  *pMotionVectorMapsMetadataSubresources;
  D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION MotionUnitPrecision;
  D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA1       PictureControlConfiguration;
} D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_MOTION_VECTORS;