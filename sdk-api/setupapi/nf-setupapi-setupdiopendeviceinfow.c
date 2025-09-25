WINSETUPAPI BOOL SetupDiOpenDeviceInfoW(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PCWSTR           DeviceInstanceId,
  [in, optional]  HWND             hwndParent,
  [in]            DWORD            OpenFlags,
  [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);