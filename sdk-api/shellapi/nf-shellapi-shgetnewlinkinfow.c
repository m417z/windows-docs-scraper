BOOL SHGetNewLinkInfoW(
  [in]  LPCWSTR pszLinkTo,
  [in]  LPCWSTR pszDir,
  [out] LPWSTR  pszName,
  [out] BOOL    *pfMustCopy,
  [in]  UINT    uFlags
);