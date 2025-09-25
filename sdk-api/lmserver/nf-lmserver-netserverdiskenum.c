NET_API_STATUS NET_API_FUNCTION NetServerDiskEnum(
  [in]      LMSTR   servername,
  [in]      DWORD   level,
  [out]     LPBYTE  *bufptr,
  [in]      DWORD   prefmaxlen,
  [out]     LPDWORD entriesread,
  [out]     LPDWORD totalentries,
  [in, out] LPDWORD resume_handle
);