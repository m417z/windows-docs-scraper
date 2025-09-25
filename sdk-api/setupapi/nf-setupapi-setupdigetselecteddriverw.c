WINSETUPAPI BOOL SetupDiGetSelectedDriverW(
  [in]           HDEVINFO           DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA   DeviceInfoData,
  [out]          PSP_DRVINFO_DATA_W DriverInfoData
);