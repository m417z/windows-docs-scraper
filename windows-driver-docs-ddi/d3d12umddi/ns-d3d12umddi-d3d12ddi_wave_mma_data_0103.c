typedef struct D3D12DDI_WAVE_MMA_DATA_0103 {
  D3D12DDI_WAVE_MMA_INPUT_DATATYPE InputDataType;
  D3D12DDI_WAVE_MMA_DIMENSION      M;
  D3D12DDI_WAVE_MMA_DIMENSION      N;
  BOOL                             Supported;
  UINT                             K;
  D3D12DDI_WAVE_MMA_ACCUM_DATATYPE AccumDataTypes;
  UINT                             RequiredWaveLaneCountMin;
  UINT                             RequiredWaveLaneCountMax;
} D3D12DDI_WAVE_MMA_DATA_0103;