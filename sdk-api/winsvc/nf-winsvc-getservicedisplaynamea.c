BOOL GetServiceDisplayNameA(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCSTR    lpServiceName,
  [out, optional] LPSTR     lpDisplayName,
  [in, out]       LPDWORD   lpcchBuffer
);