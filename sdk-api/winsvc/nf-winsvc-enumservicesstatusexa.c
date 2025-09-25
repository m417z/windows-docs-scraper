BOOL EnumServicesStatusExA(
  [in]                SC_HANDLE    hSCManager,
  [in]                SC_ENUM_TYPE InfoLevel,
  [in]                DWORD        dwServiceType,
  [in]                DWORD        dwServiceState,
  [out, optional]     LPBYTE       lpServices,
  [in]                DWORD        cbBufSize,
  [out]               LPDWORD      pcbBytesNeeded,
  [out]               LPDWORD      lpServicesReturned,
  [in, out, optional] LPDWORD      lpResumeHandle,
  [in, optional]      LPCSTR       pszGroupName
);