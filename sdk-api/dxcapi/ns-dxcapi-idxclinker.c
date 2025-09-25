struct IDxcLinker : IUnknown {
  HRESULT RegisterLibrary(
    LPCWSTR  pLibName,
    IDxcBlob *pLib
  );
  HRESULT Link(
    LPCWSTR             pEntryName,
    LPCWSTR             pTargetProfile,
    const LPCWSTR       *pLibNames,
    UINT32              libCount,
    const LPCWSTR       *pArguments,
    UINT32              argCount,
    IDxcOperationResult **ppResult
  );
};