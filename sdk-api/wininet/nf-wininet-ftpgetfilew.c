BOOL FtpGetFileW(
  [in] HINTERNET hConnect,
  [in] LPCWSTR   lpszRemoteFile,
  [in] LPCWSTR   lpszNewFile,
  [in] BOOL      fFailIfExists,
  [in] DWORD     dwFlagsAndAttributes,
  [in] DWORD     dwFlags,
  [in] DWORD_PTR dwContext
);