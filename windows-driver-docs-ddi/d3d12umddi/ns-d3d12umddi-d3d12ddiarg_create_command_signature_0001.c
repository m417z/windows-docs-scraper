typedef struct D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001 {
  UINT                                  ByteStride;
  UINT                                  NumArgumentDescs;
  const D3D12DDI_INDIRECT_ARGUMENT_DESC *pArgumentDescs;
  D3D12DDI_HROOTSIGNATURE               hRootSignature;
  UINT                                  NodeMask;
} D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001;