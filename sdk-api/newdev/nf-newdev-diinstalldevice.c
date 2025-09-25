BOOL DiInstallDevice(
  [in, optional]  HWND             hwndParent,
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in, optional]  PSP_DRVINFO_DATA DriverInfoData,
  [in]            DWORD            Flags,
  [out, optional] PBOOL            NeedReboot
);