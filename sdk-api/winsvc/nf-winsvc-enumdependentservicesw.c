BOOL EnumDependentServicesW(
  [in]            SC_HANDLE              hService,
  [in]            DWORD                  dwServiceState,
  [out, optional] LPENUM_SERVICE_STATUSW lpServices,
  [in]            DWORD                  cbBufSize,
  [out]           LPDWORD                pcbBytesNeeded,
  [out]           LPDWORD                lpServicesReturned
);