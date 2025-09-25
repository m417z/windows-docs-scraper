HRESULT CreateInstanceWithSysTx(
  [in]          IUnknown *pTransaction,
  [in]          REFCLSID rclsid,
  [in]          REFIID   riid,
  [out, retval] void     **pObject
);