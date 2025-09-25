BOOL QueryServiceConfigA(
  [in]            SC_HANDLE               hService,
  [out, optional] LPQUERY_SERVICE_CONFIGA lpServiceConfig,
  [in]            DWORD                   cbBufSize,
  [out]           LPDWORD                 pcbBytesNeeded
);