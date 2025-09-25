HRESULT D3D10CompileShader(
  [in]  LPCSTR                   pSrcData,
  [in]  SIZE_T                   SrcDataSize,
  [in]  LPCSTR                   pFileName,
  [in]  const D3D10_SHADER_MACRO *pDefines,
  [in]  LPD3D10INCLUDE           pInclude,
  [in]  LPCSTR                   pFunctionName,
  [in]  LPCSTR                   pProfile,
  [in]  UINT                     Flags,
  [out] ID3D10Blob               **ppShader,
  [out] ID3D10Blob               **ppErrorMsgs
);