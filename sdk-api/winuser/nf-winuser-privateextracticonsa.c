UINT PrivateExtractIconsA(
  [in]            LPCSTR szFileName,
  [in]            int    nIconIndex,
  [in]            int    cxIcon,
  [in]            int    cyIcon,
  [out, optional] HICON  *phicon,
  [out, optional] UINT   *piconid,
  [in]            UINT   nIcons,
  [in]            UINT   flags
);