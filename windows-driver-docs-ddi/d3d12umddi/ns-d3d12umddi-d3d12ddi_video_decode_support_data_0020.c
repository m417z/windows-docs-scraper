typedef struct D3D12DDI_VIDEO_DECODE_SUPPORT_DATA_0020 {
  UINT                                           NodeIndex;
  D3D12DDI_VIDEO_DECODE_CONFIGURATION_0020       Configuration;
  UINT                                           Width;
  UINT                                           Height;
  DXGI_FORMAT                                    DecodeFormat;
  DXGI_RATIONAL                                  FrameRate;
  UINT                                           BitRate;
  D3D12DDI_VIDEO_DECODE_SUPPORT_FLAGS_0020       SupportFlags;
  D3D12DDI_VIDEO_DECODE_CONFIGURATION_FLAGS_0020 ConfigurationFlags;
  D3D12DDI_VIDEO_DECODE_TIER_0020                DecodeTier;
} D3D12DDI_VIDEO_DECODE_SUPPORT_DATA_0020;