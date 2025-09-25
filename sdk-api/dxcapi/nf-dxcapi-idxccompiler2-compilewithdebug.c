HRESULT CompileWithDebug(
  IDxcBlob            *pSource,
  LPCWSTR             pSourceName,
  LPCWSTR             pEntryPoint,
  LPCWSTR             pTargetProfile,
  LPCWSTR             *pArguments,
  UINT32              argCount,
  const DxcDefine     *pDefines,
  UINT32              defineCount,
  IDxcIncludeHandler  *pIncludeHandler,
  IDxcOperationResult **ppResult,
  LPWSTR              *ppDebugBlobName,
  IDxcBlob            **ppDebugBlob
);