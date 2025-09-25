HRESULT CoGetInstanceFromFile(
  [in, optional] COSERVERINFO *pServerInfo,
  [in, optional] CLSID        *pClsid,
  [in, optional] IUnknown     *punkOuter,
  [in]           DWORD        dwClsCtx,
  [in]           DWORD        grfMode,
  [in]           OLECHAR      *pwszName,
  [in]           DWORD        dwCount,
  [in, out]      MULTI_QI     *pResults
);