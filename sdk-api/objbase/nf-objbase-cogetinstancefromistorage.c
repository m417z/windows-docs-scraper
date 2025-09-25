HRESULT CoGetInstanceFromIStorage(
  [in, optional] COSERVERINFO *pServerInfo,
  [in, optional] CLSID        *pClsid,
  [in, optional] IUnknown     *punkOuter,
  [in]           DWORD        dwClsCtx,
  [in]           IStorage     *pstg,
  [in]           DWORD        dwCount,
  [in, out]      MULTI_QI     *pResults
);