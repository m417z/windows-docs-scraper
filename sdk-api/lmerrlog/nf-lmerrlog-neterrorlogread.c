NET_API_STATUS NET_API_FUNCTION NetErrorLogRead(
  LPCWSTR UncServerName,
  LPWSTR  Reserved1,
  LPHLOG  ErrorLogHandle,
  DWORD   Offset,
  LPDWORD Reserved2,
  DWORD   Reserved3,
  DWORD   OffsetFlag,
  LPBYTE  *BufPtr,
  DWORD   PrefMaxSize,
  LPDWORD BytesRead,
  LPDWORD TotalAvailable
);