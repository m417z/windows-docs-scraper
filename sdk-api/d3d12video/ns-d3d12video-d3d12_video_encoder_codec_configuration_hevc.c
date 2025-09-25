typedef struct D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC {
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAGS  ConfigurationFlags;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE MinLumaCodingUnitSize;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE MaxLumaCodingUnitSize;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE MinLumaTransformUnitSize;
  D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE MaxLumaTransformUnitSize;
  UCHAR                                               max_transform_hierarchy_depth_inter;
  UCHAR                                               max_transform_hierarchy_depth_intra;
} D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC;