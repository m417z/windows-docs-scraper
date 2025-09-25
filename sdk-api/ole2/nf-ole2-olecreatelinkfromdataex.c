HRESULT OleCreateLinkFromDataEx(
  [in]      LPDATAOBJECT    pSrcDataObj,
  [in]      REFIID          riid,
  [in]      DWORD           dwFlags,
  [in]      DWORD           renderopt,
  [in]      ULONG           cFormats,
  [in]      DWORD           *rgAdvf,
  [in]      LPFORMATETC     rgFormatEtc,
  [in]      IAdviseSink     *lpAdviseSink,
  [in, out] DWORD           *rgdwConnection,
  [in]      LPOLECLIENTSITE pClientSite,
  [in]      LPSTORAGE       pStg,
  [out]     LPVOID          *ppvObj
);