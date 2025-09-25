NET_API_STATUS NET_API_FUNCTION NetErrorLogWrite(
  LPBYTE  Reserved1,
  DWORD   Code,
  LPCWSTR Component,
  LPBYTE  Buffer,
  DWORD   NumBytes,
  LPBYTE  MsgBuf,
  DWORD   StrCount,
  LPBYTE  Reserved2
);