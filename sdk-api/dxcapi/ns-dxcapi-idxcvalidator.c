struct IDxcValidator : IUnknown {
  HRESULT Validate(
    IDxcBlob            *pShader,
    UINT32              Flags,
    IDxcOperationResult **ppResult
  );
};