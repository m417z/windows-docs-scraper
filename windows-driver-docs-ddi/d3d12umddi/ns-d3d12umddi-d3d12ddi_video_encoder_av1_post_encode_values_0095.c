typedef struct D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095 {
  UINT64                                                          CompoundPredictionType;
  D3D12DDI_VIDEO_ENCODER_CODEC_AV1_LOOP_FILTER_CONFIG_0095        LoopFilter;
  D3D12DDI_VIDEO_ENCODER_CODEC_AV1_LOOP_FILTER_DELTA_CONFIG_0095  LoopFilterDelta;
  D3D12DDI_VIDEO_ENCODER_CODEC_AV1_QUANTIZATION_CONFIG_0095       Quantization;
  D3D12DDI_VIDEO_ENCODER_CODEC_AV1_QUANTIZATION_DELTA_CONFIG_0095 QuantizationDelta;
  D3D12DDI_VIDEO_ENCODER_AV1_CDEF_CONFIG_0095                     CDEF;
  D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095             SegmentationConfig;
  UINT64                                                          PrimaryRefFrame;
  UINT64                                                          ReferenceIndices[7];
} D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095;