typedef struct D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095 {
  UINT64                                       UpdateMap;
  UINT64                                       TemporalUpdate;
  UINT64                                       UpdateData;
  UINT64                                       NumSegments;
  D3D12DDI_VIDEO_ENCODER_AV1_SEGMENT_DATA_0095 SegmentsData[8];
} D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095;