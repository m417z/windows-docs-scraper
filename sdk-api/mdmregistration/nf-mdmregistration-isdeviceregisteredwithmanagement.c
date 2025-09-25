HRESULT IsDeviceRegisteredWithManagement(
  [out]           BOOL   *pfIsDeviceRegisteredWithManagement,
  [in, optional]  DWORD  cchUPN,
  [out, optional] LPWSTR pszUPN
);