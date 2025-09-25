BOOL DiUninstallDevice(
  [in]            HWND             hwndParent,
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in]            DWORD            Flags,
  [out, optional] PBOOL            NeedReboot
);