BOOL DiRollbackDriver(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in, optional]  HWND             hwndParent,
  [in]            DWORD            Flags,
  [out, optional] PBOOL            NeedReboot
);