WINSETUPAPI BOOL SetupDiGetDriverInstallParamsW(
  [in]           HDEVINFO              DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA      DeviceInfoData,
  [in]           PSP_DRVINFO_DATA_W    DriverInfoData,
  [out]          PSP_DRVINSTALL_PARAMS DriverInstallParams
);