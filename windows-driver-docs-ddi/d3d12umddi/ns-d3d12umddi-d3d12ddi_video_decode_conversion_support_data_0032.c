typedef struct D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_DATA_0032 {
  UINT                                                NodeIndex;
  D3D12DDI_VIDEO_DECODE_CONFIGURATION_0020            Configuration;
  D3D12DDI_VIDEO_SAMPLE_DESCRIPTION_0020              DecodeSample;
  D3D12DDI_VIDEO_FORMAT_DESCRIPTION_0020              OutputFormat;
  DXGI_RATIONAL                                       FrameRate;
  UINT                                                BitRate;
  D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_FLAGS_0020 SupportFlags;
  D3D12DDI_VIDEO_SCALE_SUPPORT_0032                   ScaleSupport;
} D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_DATA_0032;