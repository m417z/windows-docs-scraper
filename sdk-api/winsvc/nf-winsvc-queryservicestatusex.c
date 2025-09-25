BOOL QueryServiceStatusEx(
  [in]            SC_HANDLE      hService,
  [in]            SC_STATUS_TYPE InfoLevel,
  [out, optional] LPBYTE         lpBuffer,
  [in]            DWORD          cbBufSize,
  [out]           LPDWORD        pcbBytesNeeded
);