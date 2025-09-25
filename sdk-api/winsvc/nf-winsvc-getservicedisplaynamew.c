BOOL GetServiceDisplayNameW(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCWSTR   lpServiceName,
  [out, optional] LPWSTR    lpDisplayName,
  [in, out]       LPDWORD   lpcchBuffer
);