typedef struct D3D12DDI_SHADER_CAPS_0084 {
  D3D12DDI_SHADER_MIN_PRECISION MinPrecision;
  BOOL                          DoubleOps;
  BOOL                          ShaderSpecifiedStencilRef;
  BOOL                          TypedUAVLoadAdditionalFormats;
  BOOL                          ROVs;
  BOOL                          WaveOps;
  UINT                          WaveLaneCountMin;
  UINT                          WaveLaneCountMax;
  UINT                          TotalLaneCount;
  BOOL                          Int64Ops;
  BOOL                          Native16BitOps;
  BOOL                          AtomicInt64OnTypedResource;
  BOOL                          AtomicInt64OnGroupShared;
  BOOL                          DerivativesInMeshAndAmplificationShaders;
  D3D12DDI_WAVE_MMA_TIER        WaveMMATier;
  BOOL                          AtomicInt64OnDescriptorHeapResource;
} D3D12DDI_SHADER_CAPS_0084;