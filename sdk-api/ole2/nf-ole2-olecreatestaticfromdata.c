HRESULT OleCreateStaticFromData(
  [in]  LPDATAOBJECT    pSrcDataObj,
  [in]  REFIID          iid,
  [in]  DWORD           renderopt,
  [in]  LPFORMATETC     pFormatEtc,
  [in]  LPOLECLIENTSITE pClientSite,
  [in]  LPSTORAGE       pStg,
  [out] LPVOID          *ppvObj
);