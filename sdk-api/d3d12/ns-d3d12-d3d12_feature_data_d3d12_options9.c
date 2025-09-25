typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS9 {
  BOOL                MeshShaderPipelineStatsSupported;
  BOOL                MeshShaderSupportsFullRangeRenderTargetArrayIndex;
  BOOL                AtomicInt64OnTypedResourceSupported;
  BOOL                AtomicInt64OnGroupSharedSupported;
  BOOL                DerivativesInMeshAndAmplificationShadersSupported;
  D3D12_WAVE_MMA_TIER WaveMMATier;
} D3D12_FEATURE_DATA_D3D12_OPTIONS9;