HRESULT OleCreateLinkEx(
  [in]  LPMONIKER       pmkLinkSrc,
  [in]  REFIID          riid,
  [in]  DWORD           dwFlags,
  [in]  DWORD           renderopt,
  [in]  ULONG           cFormats,
  [in]  DWORD           *rgAdvf,
  [in]  LPFORMATETC     rgFormatEtc,
  [in]  IAdviseSink     *lpAdviseSink,
  [out] DWORD           *rgdwConnection,
  [in]  LPOLECLIENTSITE pClientSite,
  [in]  LPSTORAGE       pStg,
  [out] LPVOID          *ppvObj
);