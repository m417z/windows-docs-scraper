HRESULT CreateGeometryShaderWithStreamOutput(
  [in]            const void                       *pShaderBytecode,
  [in]            SIZE_T                           BytecodeLength,
  [in, optional]  const D3D11_SO_DECLARATION_ENTRY *pSODeclaration,
  [in]            UINT                             NumEntries,
  [in, optional]  const UINT                       *pBufferStrides,
  [in]            UINT                             NumStrides,
  [in]            UINT                             RasterizedStream,
  [in, optional]  ID3D11ClassLinkage               *pClassLinkage,
  [out, optional] ID3D11GeometryShader             **ppGeometryShader
);