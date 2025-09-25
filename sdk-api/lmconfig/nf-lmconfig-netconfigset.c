NET_API_STATUS NET_API_FUNCTION NetConfigSet(
  LPCWSTR server,
  LPCWSTR reserved1,
  LPCWSTR component,
  DWORD   level,
  DWORD   reserved2,
  LPBYTE  buf,
  DWORD   reserved3
);