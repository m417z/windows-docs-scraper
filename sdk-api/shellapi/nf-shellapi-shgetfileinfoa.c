DWORD_PTR SHGetFileInfoA(
  [in]      LPCSTR      pszPath,
            DWORD       dwFileAttributes,
  [in, out] SHFILEINFOA *psfi,
            UINT        cbFileInfo,
            UINT        uFlags
);