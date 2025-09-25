BOOL WTSSendMessageA(
  [in]  HANDLE hServer,
  [in]  DWORD  SessionId,
  [in]  LPSTR  pTitle,
  [in]  DWORD  TitleLength,
  [in]  LPSTR  pMessage,
  [in]  DWORD  MessageLength,
  [in]  DWORD  Style,
  [in]  DWORD  Timeout,
  [out] DWORD  *pResponse,
  [in]  BOOL   bWait
);