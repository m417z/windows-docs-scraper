WINSETUPAPI BOOL SetupDiSetSelectedDriverW(
  [in]      HDEVINFO           DeviceInfoSet,
  [in, out] PSP_DEVINFO_DATA   DeviceInfoData,
  [in, out] PSP_DRVINFO_DATA_W DriverInfoData
);