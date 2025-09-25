HRESULT D3D10PreprocessShader(
  [in]  LPCSTR                   pSrcData,
  [in]  SIZE_T                   SrcDataSize,
  [in]  LPCSTR                   pFileName,
  [in]  const D3D10_SHADER_MACRO *pDefines,
  [in]  LPD3D10INCLUDE           pInclude,
  [out] ID3D10Blob               **ppShaderText,
  [out] ID3D10Blob               **ppErrorMsgs
);