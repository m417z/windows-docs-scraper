BOOL ChangeServiceConfigW(
  [in]            SC_HANDLE hService,
  [in]            DWORD     dwServiceType,
  [in]            DWORD     dwStartType,
  [in]            DWORD     dwErrorControl,
  [in, optional]  LPCWSTR   lpBinaryPathName,
  [in, optional]  LPCWSTR   lpLoadOrderGroup,
  [out, optional] LPDWORD   lpdwTagId,
  [in, optional]  LPCWSTR   lpDependencies,
  [in, optional]  LPCWSTR   lpServiceStartName,
  [in, optional]  LPCWSTR   lpPassword,
  [in, optional]  LPCWSTR   lpDisplayName
);