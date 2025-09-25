typedef struct D3D12_COMMAND_SIGNATURE_DESC {
  UINT                               ByteStride;
  UINT                               NumArgumentDescs;
  const D3D12_INDIRECT_ARGUMENT_DESC *pArgumentDescs;
  UINT                               NodeMask;
} D3D12_COMMAND_SIGNATURE_DESC;