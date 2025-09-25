BOOL GetServiceKeyNameA(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCSTR    lpDisplayName,
  [out, optional] LPSTR     lpServiceName,
  [in, out]       LPDWORD   lpcchBuffer
);