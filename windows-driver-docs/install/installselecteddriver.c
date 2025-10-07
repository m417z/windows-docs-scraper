BOOL WINAPI InstallSelectedDriver(
  _In_  HWND     hwndParent,
  _In_  HDEVINFO DeviceInfoSet,
  _In_  LPCTSTR  Reserved,
  _In_  BOOL     Backup,
  _Out_ PDWORD   bReboot
);