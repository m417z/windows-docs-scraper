typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS1 {
  BOOL WaveOps;
  UINT WaveLaneCountMin;
  UINT WaveLaneCountMax;
  UINT TotalLaneCount;
  BOOL ExpandedComputeResourceStates;
  BOOL Int64ShaderOps;
} D3D12_FEATURE_DATA_D3D12_OPTIONS1;