HRESULT Compile(
  const DxcBuffer    *pSource,
  LPCWSTR            *pArguments,
  UINT32             argCount,
  IDxcIncludeHandler *pIncludeHandler,
  REFIID             riid,
  LPVOID             *ppResult
);