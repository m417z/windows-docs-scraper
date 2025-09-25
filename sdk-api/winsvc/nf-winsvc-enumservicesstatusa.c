BOOL EnumServicesStatusA(
  [in]                SC_HANDLE              hSCManager,
  [in]                DWORD                  dwServiceType,
  [in]                DWORD                  dwServiceState,
  [out, optional]     LPENUM_SERVICE_STATUSA lpServices,
  [in]                DWORD                  cbBufSize,
  [out]               LPDWORD                pcbBytesNeeded,
  [out]               LPDWORD                lpServicesReturned,
  [in, out, optional] LPDWORD                lpResumeHandle
);