HINTERNET FtpFindFirstFileW(
  [in]  HINTERNET          hConnect,
  [in]  LPCWSTR            lpszSearchFile,
  [out] LPWIN32_FIND_DATAW lpFindFileData,
  [in]  DWORD              dwFlags,
  [in]  DWORD_PTR          dwContext
);