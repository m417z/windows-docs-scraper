typedef struct D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT {
  UINT                                   NodeIndex;
  D3D12_VIDEO_DECODE_CONFIGURATION       Configuration;
  UINT                                   Width;
  UINT                                   Height;
  DXGI_FORMAT                            DecodeFormat;
  DXGI_RATIONAL                          FrameRate;
  UINT                                   BitRate;
  D3D12_VIDEO_DECODE_SUPPORT_FLAGS       SupportFlags;
  D3D12_VIDEO_DECODE_CONFIGURATION_FLAGS ConfigurationFlags;
  D3D12_VIDEO_DECODE_TIER                DecodeTier;
} D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT;