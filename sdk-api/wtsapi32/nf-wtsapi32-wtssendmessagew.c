BOOL WTSSendMessageW(
  [in]  HANDLE hServer,
  [in]  DWORD  SessionId,
  [in]  LPWSTR pTitle,
  [in]  DWORD  TitleLength,
  [in]  LPWSTR pMessage,
  [in]  DWORD  MessageLength,
  [in]  DWORD  Style,
  [in]  DWORD  Timeout,
  [out] DWORD  *pResponse,
  [in]  BOOL   bWait
);