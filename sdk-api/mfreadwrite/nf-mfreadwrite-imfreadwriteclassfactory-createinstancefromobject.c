HRESULT CreateInstanceFromObject(
  [in]  REFCLSID      clsid,
  [in]  IUnknown      *punkObject,
  [in]  IMFAttributes *pAttributes,
  [in]  REFIID        riid,
  [out] LPVOID        *ppvObject
);