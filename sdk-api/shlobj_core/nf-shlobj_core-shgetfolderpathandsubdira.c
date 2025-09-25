HRESULT SHGetFolderPathAndSubDirA(
  [in]  HWND   hwnd,
  [in]  int    csidl,
  [in]  HANDLE hToken,
  [in]  DWORD  dwFlags,
  [in]  LPCSTR pszSubDir,
  [out] LPSTR  pszPath
);