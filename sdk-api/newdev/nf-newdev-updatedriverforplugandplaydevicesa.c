BOOL UpdateDriverForPlugAndPlayDevicesA(
  [in, optional]  HWND   hwndParent,
  [in]            LPCSTR HardwareId,
  [in]            LPCSTR FullInfPath,
  [in]            DWORD  InstallFlags,
  [out, optional] PBOOL  bRebootRequired
);