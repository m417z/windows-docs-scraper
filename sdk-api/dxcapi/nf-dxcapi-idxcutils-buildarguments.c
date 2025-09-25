HRESULT BuildArguments(
  LPCWSTR          pSourceName,
  LPCWSTR          pEntryPoint,
  LPCWSTR          pTargetProfile,
  LPCWSTR          *pArguments,
  UINT32           argCount,
  const DxcDefine  *pDefines,
  UINT32           defineCount,
  IDxcCompilerArgs **ppArgs
);