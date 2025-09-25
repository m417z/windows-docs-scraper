struct IDxcContainerReflection : IUnknown {
  HRESULT Load(
    IDxcBlob *pContainer
  );
  HRESULT GetPartCount(
    UINT32 *pResult
  );
  HRESULT GetPartKind(
    UINT32 idx,
    UINT32 *pResult
  );
  HRESULT GetPartContent(
    UINT32   idx,
    IDxcBlob **ppResult
  );
  HRESULT FindFirstPartKind(
    UINT32 kind,
    UINT32 *pResult
  );
  HRESULT GetPartReflection(
    UINT32 idx,
    REFIID iid,
    void   **ppvObject
  );
};