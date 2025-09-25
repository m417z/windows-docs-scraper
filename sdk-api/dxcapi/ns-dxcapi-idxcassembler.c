struct IDxcAssembler : IUnknown {
  HRESULT AssembleToContainer(
    IDxcBlob            *pShader,
    IDxcOperationResult **ppResult
  );
};