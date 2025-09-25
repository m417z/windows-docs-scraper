typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS6 {
  BOOL                             AdditionalShadingRatesSupported;
  BOOL                             PerPrimitiveShadingRateSupportedWithViewportIndexing;
  D3D12_VARIABLE_SHADING_RATE_TIER VariableShadingRateTier;
  UINT                             ShadingRateImageTileSize;
  BOOL                             BackgroundProcessingSupported;
} D3D12_FEATURE_DATA_D3D12_OPTIONS6;