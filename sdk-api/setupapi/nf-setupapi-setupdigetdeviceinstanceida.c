WINSETUPAPI BOOL SetupDiGetDeviceInstanceIdA(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [out, optional] PSTR             DeviceInstanceId,
  [in]            DWORD            DeviceInstanceIdSize,
  [out, optional] PDWORD           RequiredSize
);