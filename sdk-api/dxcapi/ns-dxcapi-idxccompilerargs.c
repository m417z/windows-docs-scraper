struct IDxcCompilerArgs : IUnknown {
  LPCWSTR * GetArguments();
  UINT32  GetCount();
  HRESULT AddArguments(
    LPCWSTR *pArguments,
    UINT32  argCount
  );
  HRESULT AddArgumentsUTF8(
    LPCSTR *pArguments,
    UINT32 argCount
  );
  HRESULT AddDefines(
    const DxcDefine *pDefines,
    UINT32          defineCount
  );
};