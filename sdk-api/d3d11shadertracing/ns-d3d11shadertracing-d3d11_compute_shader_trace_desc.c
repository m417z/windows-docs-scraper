typedef struct D3D11_COMPUTE_SHADER_TRACE_DESC {
  UINT64 Invocation;
  UINT   ThreadIDInGroup[3];
  UINT   ThreadGroupID[3];
} D3D11_COMPUTE_SHADER_TRACE_DESC;