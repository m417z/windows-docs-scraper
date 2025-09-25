typedef struct D3D12_FEATURE_DATA_VIDEO_DECODE_CONVERSION_SUPPORT {
  UINT                                        NodeIndex;
  D3D12_VIDEO_DECODE_CONFIGURATION            Configuration;
  D3D12_VIDEO_SAMPLE                          DecodeSample;
  D3D12_VIDEO_FORMAT                          OutputFormat;
  DXGI_RATIONAL                               FrameRate;
  UINT                                        BitRate;
  D3D12_VIDEO_DECODE_CONVERSION_SUPPORT_FLAGS SupportFlags;
  D3D12_VIDEO_SCALE_SUPPORT                   ScaleSupport;
} D3D12_FEATURE_DATA_VIDEO_DECODE_CONVERSION_SUPPORT;