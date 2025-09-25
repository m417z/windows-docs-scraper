WINSETUPAPI BOOL SetupDiSetDriverInstallParamsA(
  [in]           HDEVINFO              DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA      DeviceInfoData,
  [in]           PSP_DRVINFO_DATA_A    DriverInfoData,
  [in]           PSP_DRVINSTALL_PARAMS DriverInstallParams
);