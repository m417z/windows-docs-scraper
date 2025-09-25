WINSETUPAPI BOOL SetupDiGetSelectedDriverA(
  [in]           HDEVINFO           DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA   DeviceInfoData,
  [out]          PSP_DRVINFO_DATA_A DriverInfoData
);