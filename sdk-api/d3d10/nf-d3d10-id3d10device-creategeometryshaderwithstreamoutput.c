HRESULT CreateGeometryShaderWithStreamOutput(
  [in]  const void                       *pShaderBytecode,
  [in]  SIZE_T                           BytecodeLength,
  [in]  const D3D10_SO_DECLARATION_ENTRY *pSODeclaration,
  [in]  UINT                             NumEntries,
  [in]  UINT                             OutputStreamStride,
  [out] ID3D10GeometryShader             **ppGeometryShader
);