NET_API_STATUS NET_API_FUNCTION NetFileEnum(
  [in]      LMSTR      servername,
  [in]      LMSTR      basepath,
  [in]      LMSTR      username,
  [in]      DWORD      level,
  [out]     LPBYTE     *bufptr,
  [in]      DWORD      prefmaxlen,
  [out]     LPDWORD    entriesread,
  [out]     LPDWORD    totalentries,
  [in, out] PDWORD_PTR resume_handle
);