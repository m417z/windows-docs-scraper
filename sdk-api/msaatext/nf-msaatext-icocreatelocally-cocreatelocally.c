HRESULT CoCreateLocally(
  [in]  REFCLSID rclsid,
  [in]  DWORD    dwClsContext,
  [in]  REFIID   riid,
  [out] IUnknown **punk,
  [in]  REFIID   riidParam,
  [in]  IUnknown *punkParam,
  [in]  VARIANT  varParam
);