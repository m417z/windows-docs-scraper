SC_HANDLE CreateServiceW(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCWSTR   lpServiceName,
  [in, optional]  LPCWSTR   lpDisplayName,
  [in]            DWORD     dwDesiredAccess,
  [in]            DWORD     dwServiceType,
  [in]            DWORD     dwStartType,
  [in]            DWORD     dwErrorControl,
  [in, optional]  LPCWSTR   lpBinaryPathName,
  [in, optional]  LPCWSTR   lpLoadOrderGroup,
  [out, optional] LPDWORD   lpdwTagId,
  [in, optional]  LPCWSTR   lpDependencies,
  [in, optional]  LPCWSTR   lpServiceStartName,
  [in, optional]  LPCWSTR   lpPassword
);