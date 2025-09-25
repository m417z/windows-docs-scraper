BOOL DiShowUpdateDevice(
  [in, optional]  HWND             hwndParent,
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in]            DWORD            Flags,
  [out, optional] PBOOL            NeedReboot
);