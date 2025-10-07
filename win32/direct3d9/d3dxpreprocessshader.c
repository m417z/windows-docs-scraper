HRESULT D3DXPreprocessShader(
  _In_        LPCSTR        pSrcData,
  _In_        UINT          SrcDataSize,
  _In_  const D3DXMACRO     *pDefines,
  _In_        LPD3DXINCLUDE pInclude,
  _Out_       LPD3DXBUFFER  *ppShaderText,
  _Out_       LPD3DXBUFFER  *ppErrorMsgs
);