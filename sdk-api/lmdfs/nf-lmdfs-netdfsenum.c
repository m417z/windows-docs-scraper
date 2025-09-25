NET_API_STATUS NET_API_FUNCTION NetDfsEnum(
  [in]      LPWSTR  DfsName,
  [in]      DWORD   Level,
  [in]      DWORD   PrefMaxLen,
  [out]     LPBYTE  *Buffer,
  [out]     LPDWORD EntriesRead,
  [in, out] LPDWORD ResumeHandle
);