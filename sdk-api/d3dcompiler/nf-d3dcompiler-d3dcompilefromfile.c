HRESULT D3DCompileFromFile(
  [in]            LPCWSTR                pFileName,
  [in, optional]  const D3D_SHADER_MACRO *pDefines,
  [in, optional]  ID3DInclude            *pInclude,
  [in]            LPCSTR                 pEntrypoint,
  [in]            LPCSTR                 pTarget,
  [in]            UINT                   Flags1,
  [in]            UINT                   Flags2,
  [out]           ID3DBlob               **ppCode,
  [out, optional] ID3DBlob               **ppErrorMsgs
);