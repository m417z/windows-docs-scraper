SC_HANDLE CreateServiceA(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCSTR    lpServiceName,
  [in, optional]  LPCSTR    lpDisplayName,
  [in]            DWORD     dwDesiredAccess,
  [in]            DWORD     dwServiceType,
  [in]            DWORD     dwStartType,
  [in]            DWORD     dwErrorControl,
  [in, optional]  LPCSTR    lpBinaryPathName,
  [in, optional]  LPCSTR    lpLoadOrderGroup,
  [out, optional] LPDWORD   lpdwTagId,
  [in, optional]  LPCSTR    lpDependencies,
  [in, optional]  LPCSTR    lpServiceStartName,
  [in, optional]  LPCSTR    lpPassword
);