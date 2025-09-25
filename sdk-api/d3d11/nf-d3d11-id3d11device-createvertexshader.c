HRESULT CreateVertexShader(
  [in]            const void         *pShaderBytecode,
  [in]            SIZE_T             BytecodeLength,
  [in, optional]  ID3D11ClassLinkage *pClassLinkage,
  [out, optional] ID3D11VertexShader **ppVertexShader
);