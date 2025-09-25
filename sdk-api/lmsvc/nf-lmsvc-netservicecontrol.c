NET_API_STATUS NET_API_FUNCTION NetServiceControl(
  LPCWSTR servername,
  LPCWSTR service,
  DWORD   opcode,
  DWORD   arg,
  LPBYTE  *bufptr
);