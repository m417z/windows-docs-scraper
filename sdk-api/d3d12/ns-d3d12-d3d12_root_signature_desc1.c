typedef struct D3D12_ROOT_SIGNATURE_DESC1 {
  UINT                            NumParameters;
  const D3D12_ROOT_PARAMETER1     *pParameters;
  UINT                            NumStaticSamplers;
  const D3D12_STATIC_SAMPLER_DESC *pStaticSamplers;
  D3D12_ROOT_SIGNATURE_FLAGS      Flags;
} D3D12_ROOT_SIGNATURE_DESC1;