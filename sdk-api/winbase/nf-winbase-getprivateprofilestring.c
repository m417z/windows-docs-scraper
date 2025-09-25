DWORD GetPrivateProfileString(
  [in]  LPCTSTR lpAppName,
  [in]  LPCTSTR lpKeyName,
  [in]  LPCTSTR lpDefault,
  [out] LPTSTR  lpReturnedString,
  [in]  DWORD   nSize,
  [in]  LPCTSTR lpFileName
);