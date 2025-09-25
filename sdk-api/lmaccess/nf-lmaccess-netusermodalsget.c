NET_API_STATUS NET_API_FUNCTION NetUserModalsGet(
  [in, optional] LPCWSTR servername,
  [in]           DWORD   level,
  [out]          LPBYTE  *bufptr
);