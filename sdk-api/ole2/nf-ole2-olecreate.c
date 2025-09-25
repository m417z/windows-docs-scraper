HRESULT OleCreate(
  [in]  REFCLSID        rclsid,
  [in]  REFIID          riid,
  [in]  DWORD           renderopt,
  [in]  LPFORMATETC     pFormatEtc,
  [in]  LPOLECLIENTSITE pClientSite,
  [in]  LPSTORAGE       pStg,
  [out] LPVOID          *ppvObj
);