BOOL SHOpenPropSheetA(
  [in, optional] LPCSTR        pszCaption,
  [in, optional] HKEY []       ahkeys,
                 UINT          ckeys,
  [in, optional] const CLSID   *pclsidDefault,
  [in]           IDataObject   *pdtobj,
  [in, optional] IShellBrowser *psb,
  [in, optional] LPCSTR        pStartPage
);