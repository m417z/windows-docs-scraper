typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS4 {
  BOOL                                     MSAA64KBAlignedTextureSupported;
  D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER SharedResourceCompatibilityTier;
  BOOL                                     Native16BitShaderOpsSupported;
} D3D12_FEATURE_DATA_D3D12_OPTIONS4;