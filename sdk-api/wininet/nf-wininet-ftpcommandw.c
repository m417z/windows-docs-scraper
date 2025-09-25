BOOL FtpCommandW(
  [in]  HINTERNET hConnect,
  [in]  BOOL      fExpectResponse,
  [in]  DWORD     dwFlags,
  [in]  LPCWSTR   lpszCommand,
  [in]  DWORD_PTR dwContext,
  [out] HINTERNET *phFtpCommand
);