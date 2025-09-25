NET_API_STATUS NET_API_FUNCTION NetAuditRead(
  LPCWSTR server,
  LPCWSTR service,
  LPHLOG  auditloghandle,
  DWORD   offset,
  LPDWORD reserved1,
  DWORD   reserved2,
  DWORD   offsetflag,
  LPBYTE  *bufptr,
  DWORD   prefmaxlen,
  LPDWORD bytesread,
  LPDWORD totalavailable
);