HRESULT SHGetFolderPathAndSubDirW(
  [in]  HWND    hwnd,
  [in]  int     csidl,
  [in]  HANDLE  hToken,
  [in]  DWORD   dwFlags,
  [in]  LPCWSTR pszSubDir,
  [out] LPWSTR  pszPath
);