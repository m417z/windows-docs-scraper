BOOL SHOpenPropSheetW(
  [in, optional] LPCWSTR       pszCaption,
  [in, optional] HKEY []       ahkeys,
                 UINT          ckeys,
  [in, optional] const CLSID   *pclsidDefault,
  [in]           IDataObject   *pdtobj,
  [in, optional] IShellBrowser *psb,
  [in, optional] LPCWSTR       pStartPage
);