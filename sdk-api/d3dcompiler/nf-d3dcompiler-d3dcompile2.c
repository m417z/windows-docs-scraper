HRESULT D3DCompile2(
  [in]            LPCVOID                pSrcData,
  [in]            SIZE_T                 SrcDataSize,
  [in, optional]  LPCSTR                 pSourceName,
  [in, optional]  const D3D_SHADER_MACRO *pDefines,
  [in, optional]  ID3DInclude            *pInclude,
  [in]            LPCSTR                 pEntrypoint,
  [in]            LPCSTR                 pTarget,
  [in]            UINT                   Flags1,
  [in]            UINT                   Flags2,
  [in]            UINT                   SecondaryDataFlags,
  [in, optional]  LPCVOID                pSecondaryData,
  [in]            SIZE_T                 SecondaryDataSize,
  [out]           ID3DBlob               **ppCode,
  [out, optional] ID3DBlob               **ppErrorMsgs
);