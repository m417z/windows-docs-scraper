HRESULT D3D10CompileEffectFromMemory(
  [in]  void                     *pData,
  [in]  SIZE_T                   DataLength,
  [in]  LPCSTR                   pSrcFileName,
  [in]  const D3D10_SHADER_MACRO *pDefines,
  [in]  ID3D10Include            *pInclude,
  [in]  UINT                     HLSLFlags,
  [in]  UINT                     FXFlags,
  [out] ID3D10Blob               **ppCompiledEffect,
  [out] ID3D10Blob               **ppErrors
);