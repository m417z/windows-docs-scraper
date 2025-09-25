HRESULT CreateInstanceFromURL(
  [in]  REFCLSID      clsid,
  [in]  LPCWSTR       pwszURL,
  [in]  IMFAttributes *pAttributes,
  [in]  REFIID        riid,
  [out] LPVOID        *ppvObject
);