WINSETUPAPI BOOL SetupDiGetDeviceInstallParamsW(
  [in]           HDEVINFO                DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA        DeviceInfoData,
  [out]          PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
);