WINSETUPAPI BOOL SetupDiDestroyDriverInfoList(
  [in]           HDEVINFO         DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
  [in]           DWORD            DriverType
);