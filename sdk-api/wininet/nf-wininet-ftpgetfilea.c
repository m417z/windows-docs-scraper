BOOL FtpGetFileA(
  [in] HINTERNET hConnect,
  [in] LPCSTR    lpszRemoteFile,
  [in] LPCSTR    lpszNewFile,
  [in] BOOL      fFailIfExists,
  [in] DWORD     dwFlagsAndAttributes,
  [in] DWORD     dwFlags,
  [in] DWORD_PTR dwContext
);