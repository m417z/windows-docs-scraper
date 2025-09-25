BOOL GetServiceKeyNameW(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCWSTR   lpDisplayName,
  [out, optional] LPWSTR    lpServiceName,
  [in, out]       LPDWORD   lpcchBuffer
);