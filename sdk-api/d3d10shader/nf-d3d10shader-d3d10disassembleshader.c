HRESULT D3D10DisassembleShader(
  [in]  const void *pShader,
  [in]  SIZE_T     BytecodeLength,
  [in]  BOOL       EnableColorCode,
  [in]  LPCSTR     pComments,
  [out] ID3D10Blob **ppDisassembly
);