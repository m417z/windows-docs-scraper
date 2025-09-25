WINSETUPAPI BOOL SetupDiOpenDeviceInfoA(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PCSTR            DeviceInstanceId,
  [in, optional]  HWND             hwndParent,
  [in]            DWORD            OpenFlags,
  [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);