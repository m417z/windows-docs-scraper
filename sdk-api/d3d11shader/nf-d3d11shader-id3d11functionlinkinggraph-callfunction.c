HRESULT CallFunction(
  [in, optional] LPCSTR            pModuleInstanceNamespace,
  [in]           ID3D11Module      *pModuleWithFunctionPrototype,
  [in]           LPCSTR            pFunctionName,
  [out]          ID3D11LinkingNode **ppCallNode
);