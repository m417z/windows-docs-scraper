typedef struct D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS {
  DXGI_FORMAT                           Format;
  UINT                                  SampleCount;
  D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS Flags;
  UINT                                  NumQualityLevels;
} D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS;