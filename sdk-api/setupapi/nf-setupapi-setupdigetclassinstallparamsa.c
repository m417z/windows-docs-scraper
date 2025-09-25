WINSETUPAPI BOOL SetupDiGetClassInstallParamsA(
  [in]            HDEVINFO                DeviceInfoSet,
  [in, optional]  PSP_DEVINFO_DATA        DeviceInfoData,
  [out, optional] PSP_CLASSINSTALL_HEADER ClassInstallParams,
  [in]            DWORD                   ClassInstallParamsSize,
  [out, optional] PDWORD                  RequiredSize
);