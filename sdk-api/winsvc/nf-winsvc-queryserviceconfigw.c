BOOL QueryServiceConfigW(
  [in]            SC_HANDLE               hService,
  [out, optional] LPQUERY_SERVICE_CONFIGW lpServiceConfig,
  [in]            DWORD                   cbBufSize,
  [out]           LPDWORD                 pcbBytesNeeded
);