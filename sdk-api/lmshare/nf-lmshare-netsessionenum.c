NET_API_STATUS NET_API_FUNCTION NetSessionEnum(
  [in]      LMSTR   servername,
  [in]      LMSTR   UncClientName,
  [in]      LMSTR   username,
  [in]      DWORD   level,
  [out]     LPBYTE  *bufptr,
  [in]      DWORD   prefmaxlen,
  [out]     LPDWORD entriesread,
  [out]     LPDWORD totalentries,
  [in, out] LPDWORD resume_handle
);