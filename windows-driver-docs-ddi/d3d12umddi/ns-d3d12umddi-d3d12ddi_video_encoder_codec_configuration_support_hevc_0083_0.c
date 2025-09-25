typedef struct D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0 {
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0083_0 SupportFlags;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080          MinLumaCodingUnitSize;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080          MaxLumaCodingUnitSize;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE_0082_0        MinLumaTransformUnitSize;
  D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE_0082_0        MaxLumaTransformUnitSize;
  UCHAR                                                                max_transform_hierarchy_depth_inter;
  UCHAR                                                                max_transform_hierarchy_depth_intra;
} D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0;