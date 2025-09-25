HRESULT Preprocess(
  IDxcBlob            *pSource,
  LPCWSTR             pSourceName,
  LPCWSTR             *pArguments,
  UINT32              argCount,
  const DxcDefine     *pDefines,
  UINT32              defineCount,
  IDxcIncludeHandler  *pIncludeHandler,
  IDxcOperationResult **ppResult
);