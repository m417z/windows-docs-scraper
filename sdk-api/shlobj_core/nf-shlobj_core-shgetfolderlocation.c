SHSTDAPI SHGetFolderLocation(
  [in]  HWND             hwnd,
  [in]  int              csidl,
  [in]  HANDLE           hToken,
  [in]  DWORD            dwFlags,
  [out] PIDLIST_ABSOLUTE *ppidl
);