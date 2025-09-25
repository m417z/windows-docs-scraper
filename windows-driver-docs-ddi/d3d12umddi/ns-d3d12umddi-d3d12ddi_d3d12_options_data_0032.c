typedef struct D3D12DDI_D3D12_OPTIONS_DATA_0032 {
  D3D12DDI_RESOURCE_BINDING_TIER              ResourceBindingTier;
  D3D12DDI_CONSERVATIVE_RASTERIZATION_TIER    ConservativeRasterizationTier;
  D3D12DDI_TILED_RESOURCES_TIER               TiledResourcesTier;
  D3D12DDI_CROSS_NODE_SHARING_TIER            CrossNodeSharingTier;
  BOOL                                        VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation;
  BOOL                                        OutputMergerLogicOp;
  D3D12DDI_RESOURCE_HEAP_TIER                 ResourceHeapTier;
  BOOL                                        DepthBoundsTestSupported;
  D3D12DDI_PROGRAMMABLE_SAMPLE_POSITIONS_TIER ProgrammableSamplePositionsTier;
  BOOL                                        CopyQueueTimestampQueriesSupported;
  D3D12DDI_COMMAND_QUEUE_FLAGS                WriteBufferImmediateQueueFlags;
} D3D12DDI_D3D12_OPTIONS_DATA_0032;