typedef struct D3D11_FEATURE_DATA_D3D11_OPTIONS2 {
  BOOL                                  PSSpecifiedStencilRefSupported;
  BOOL                                  TypedUAVLoadAdditionalFormats;
  BOOL                                  ROVsSupported;
  D3D11_CONSERVATIVE_RASTERIZATION_TIER ConservativeRasterizationTier;
  D3D11_TILED_RESOURCES_TIER            TiledResourcesTier;
  BOOL                                  MapOnDefaultTextures;
  BOOL                                  StandardSwizzle;
  BOOL                                  UnifiedMemoryArchitecture;
} D3D11_FEATURE_DATA_D3D11_OPTIONS2;