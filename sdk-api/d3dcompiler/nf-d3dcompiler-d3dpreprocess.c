HRESULT D3DPreprocess(
  [in]            LPCVOID                pSrcData,
  [in]            SIZE_T                 SrcDataSize,
  [in, optional]  LPCSTR                 pSourceName,
  [in, optional]  const D3D_SHADER_MACRO *pDefines,
  [in, optional]  ID3DInclude            *pInclude,
  [out]           ID3DBlob               **ppCodeText,
  [out, optional] ID3DBlob               **ppErrorMsgs
);