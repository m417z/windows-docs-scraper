struct IDxcCompiler : IUnknown {
  HRESULT Compile(
    IDxcBlob            *pSource,
    LPCWSTR             pSourceName,
    LPCWSTR             pEntryPoint,
    LPCWSTR             pTargetProfile,
    LPCWSTR             *pArguments,
    UINT32              argCount,
    const DxcDefine     *pDefines,
    UINT32              defineCount,
    IDxcIncludeHandler  *pIncludeHandler,
    IDxcOperationResult **ppResult
  );
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
  HRESULT Disassemble(
    IDxcBlob         *pSource,
    IDxcBlobEncoding **ppDisassembly
  );
};