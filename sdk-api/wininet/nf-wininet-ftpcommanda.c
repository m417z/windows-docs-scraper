BOOL FtpCommandA(
  [in]  HINTERNET hConnect,
  [in]  BOOL      fExpectResponse,
  [in]  DWORD     dwFlags,
  [in]  LPCSTR    lpszCommand,
  [in]  DWORD_PTR dwContext,
  [out] HINTERNET *phFtpCommand
);