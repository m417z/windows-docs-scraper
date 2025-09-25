typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS {
  BOOL                                  DoublePrecisionFloatShaderOps;
  BOOL                                  OutputMergerLogicOp;
  D3D12_SHADER_MIN_PRECISION_SUPPORT    MinPrecisionSupport;
  D3D12_TILED_RESOURCES_TIER            TiledResourcesTier;
  D3D12_RESOURCE_BINDING_TIER           ResourceBindingTier;
  BOOL                                  PSSpecifiedStencilRefSupported;
  BOOL                                  TypedUAVLoadAdditionalFormats;
  BOOL                                  ROVsSupported;
  D3D12_CONSERVATIVE_RASTERIZATION_TIER ConservativeRasterizationTier;
  UINT                                  MaxGPUVirtualAddressBitsPerResource;
  BOOL                                  StandardSwizzle64KBSupported;
  D3D12_CROSS_NODE_SHARING_TIER         CrossNodeSharingTier;
  BOOL                                  CrossAdapterRowMajorTextureSupported;
  BOOL                                  VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation;
  D3D12_RESOURCE_HEAP_TIER              ResourceHeapTier;
} D3D12_FEATURE_DATA_D3D12_OPTIONS;