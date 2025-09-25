BOOL UpdateDriverForPlugAndPlayDevicesW(
  [in, optional]  HWND    hwndParent,
  [in]            LPCWSTR HardwareId,
  [in]            LPCWSTR FullInfPath,
  [in]            DWORD   InstallFlags,
  [out, optional] PBOOL   bRebootRequired
);