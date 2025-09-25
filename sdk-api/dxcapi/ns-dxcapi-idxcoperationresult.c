struct IDxcOperationResult : IUnknown {
  HRESULT GetStatus(
    HRESULT *pStatus
  );
  HRESULT GetResult(
    IDxcBlob **ppResult
  );
  HRESULT GetErrorBuffer(
    IDxcBlobEncoding **ppErrors
  );
};