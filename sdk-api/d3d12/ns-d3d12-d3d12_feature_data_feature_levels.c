typedef struct D3D12_FEATURE_DATA_FEATURE_LEVELS {
  UINT                    NumFeatureLevels;
  const D3D_FEATURE_LEVEL *pFeatureLevelsRequested;
  D3D_FEATURE_LEVEL       MaxSupportedFeatureLevel;
} D3D12_FEATURE_DATA_FEATURE_LEVELS;