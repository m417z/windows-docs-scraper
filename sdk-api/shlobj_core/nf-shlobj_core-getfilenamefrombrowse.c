BOOL GetFileNameFromBrowse(
  [in, optional] HWND   hwnd,
  [in, out]      PWSTR  pszFilePath,
                 UINT   cchFilePath,
  [in, optional] PCWSTR pszWorkingDir,
  [in]           PCWSTR pszDefExt,
  [in, optional] PCWSTR pszFilters,
  [in, optional] PCWSTR pszTitle
);