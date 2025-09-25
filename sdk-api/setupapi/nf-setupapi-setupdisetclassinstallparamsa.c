WINSETUPAPI BOOL SetupDiSetClassInstallParamsA(
  [in]           HDEVINFO                DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA        DeviceInfoData,
  [in, optional] PSP_CLASSINSTALL_HEADER ClassInstallParams,
  [in]           DWORD                   ClassInstallParamsSize
);