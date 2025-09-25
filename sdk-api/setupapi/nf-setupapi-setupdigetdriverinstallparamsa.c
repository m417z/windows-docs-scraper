WINSETUPAPI BOOL SetupDiGetDriverInstallParamsA(
  [in]           HDEVINFO              DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA      DeviceInfoData,
  [in]           PSP_DRVINFO_DATA_A    DriverInfoData,
  [out]          PSP_DRVINSTALL_PARAMS DriverInstallParams
);