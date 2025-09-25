HRESULT SHGetUnreadMailCountW(
  [in, optional]  HKEY     hKeyUser,
  [in, optional]  LPCWSTR  pszMailAddress,
  [out, optional] DWORD    *pdwCount,
  [out, optional] FILETIME *pFileTime,
  [out, optional] LPWSTR   pszShellExecuteCommand,
                  int      cchShellExecuteCommand
);