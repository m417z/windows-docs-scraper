HRESULT OleCreateLinkToFile(
  [in]  LPCOLESTR       lpszFileName,
  [in]  REFIID          riid,
  [in]  DWORD           renderopt,
  [in]  LPFORMATETC     lpFormatEtc,
  [in]  LPOLECLIENTSITE pClientSite,
  [in]  LPSTORAGE       pStg,
  [out] LPVOID          *ppvObj
);