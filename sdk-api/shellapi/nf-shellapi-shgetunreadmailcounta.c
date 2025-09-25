HRESULT SHGetUnreadMailCountA(
  [in, optional]  HKEY     hKeyUser,
  [in, optional]  LPCSTR   pszMailAddress,
  [out, optional] DWORD    *pdwCount,
  [out, optional] FILETIME *pFileTime,
  [out, optional] LPSTR    pszShellExecuteCommand,
                  int      cchShellExecuteCommand
);