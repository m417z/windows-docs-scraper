struct IDxcIncludeHandler : IUnknown {
  HRESULT LoadSource(
    LPCWSTR  pFilename,
    IDxcBlob **ppIncludeSource
  );
};