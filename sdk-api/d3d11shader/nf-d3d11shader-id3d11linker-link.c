HRESULT Link(
  [in]            ID3D11ModuleInstance *pEntry,
  [in]            LPCSTR               pEntryName,
  [in]            LPCSTR               pTargetName,
  [in]            UINT                 uFlags,
  [out]           ID3DBlob             **ppShaderBlob,
  [out, optional] ID3DBlob             **ppErrorBuffer
);