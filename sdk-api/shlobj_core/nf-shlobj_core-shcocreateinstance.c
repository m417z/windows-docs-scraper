SHSTDAPI SHCoCreateInstance(
  [in, optional] PCWSTR      pszCLSID,
  [in, optional] const CLSID *pclsid,
  [in, optional] IUnknown    *pUnkOuter,
  [in]           REFIID      riid,
  [out]          void        **ppv
);