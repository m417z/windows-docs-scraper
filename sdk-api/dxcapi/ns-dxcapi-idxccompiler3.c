struct IDxcCompiler3 : IUnknown {
  HRESULT Compile(
    const DxcBuffer    *pSource,
    LPCWSTR            *pArguments,
    UINT32             argCount,
    IDxcIncludeHandler *pIncludeHandler,
    REFIID             riid,
    LPVOID             *ppResult
  );
  HRESULT Disassemble(
    const DxcBuffer *pObject,
    REFIID          riid,
    LPVOID          *ppResult
  );
};