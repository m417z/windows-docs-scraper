NET_API_STATUS NET_API_FUNCTION NetServerEnum(
  [in, optional]      LMCSTR  servername,
  [in]                DWORD   level,
  [out]               LPBYTE  *bufptr,
  [in]                DWORD   prefmaxlen,
  [out]               LPDWORD entriesread,
  [out]               LPDWORD totalentries,
  [in]                DWORD   servertype,
  [in, optional]      LMCSTR  domain,
  [in, out, optional] LPDWORD resume_handle
);