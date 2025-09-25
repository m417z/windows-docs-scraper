WINSETUPAPI BOOL SetupDiGetDeviceInstanceIdW(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [out, optional] PWSTR            DeviceInstanceId,
  [in]            DWORD            DeviceInstanceIdSize,
  [out, optional] PDWORD           RequiredSize
);