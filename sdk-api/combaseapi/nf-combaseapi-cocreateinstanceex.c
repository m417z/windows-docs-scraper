HRESULT CoCreateInstanceEx(
  [in]      REFCLSID     Clsid,
  [in]      IUnknown     *punkOuter,
  [in]      DWORD        dwClsCtx,
  [in]      COSERVERINFO *pServerInfo,
  [in]      DWORD        dwCount,
  [in, out] MULTI_QI     *pResults
);