HRESULT CoCreateInstanceFromApp(
  [in]           REFCLSID Clsid,
  [in, optional] IUnknown *punkOuter,
  [in]           DWORD    dwClsCtx,
  [in, optional] PVOID    reserved,
  [in]           DWORD    dwCount,
  [in, out]      MULTI_QI *pResults
);