typedef struct D3D11_FEATURE_DATA_D3D11_OPTIONS1 {
  D3D11_TILED_RESOURCES_TIER TiledResourcesTier;
  BOOL                       MinMaxFiltering;
  BOOL                       ClearViewAlsoSupportsDepthOnlyFormats;
  BOOL                       MapOnDefaultBuffers;
} D3D11_FEATURE_DATA_D3D11_OPTIONS1;