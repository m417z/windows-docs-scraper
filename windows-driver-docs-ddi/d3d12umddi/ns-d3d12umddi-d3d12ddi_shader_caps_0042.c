typedef struct D3D12DDI_SHADER_CAPS_0042 {
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
} D3D12DDI_SHADER_CAPS_0042;