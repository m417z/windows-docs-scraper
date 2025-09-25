BOOL PathMakeUniqueName(
  [out]          PWSTR  pszUniqueName,
                 UINT   cchMax,
  [in]           PCWSTR pszTemplate,
  [in, optional] PCWSTR pszLongPlate,
  [in, optional] PCWSTR pszDir
);