DWORD_PTR SHGetFileInfoW(
  [in]      LPCWSTR     pszPath,
            DWORD       dwFileAttributes,
  [in, out] SHFILEINFOW *psfi,
            UINT        cbFileInfo,
            UINT        uFlags
);