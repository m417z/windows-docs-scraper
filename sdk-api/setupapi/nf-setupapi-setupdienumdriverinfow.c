WINSETUPAPI BOOL SetupDiEnumDriverInfoW(
  [in]           HDEVINFO           DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA   DeviceInfoData,
  [in]           DWORD              DriverType,
  [in]           DWORD              MemberIndex,
  [out]          PSP_DRVINFO_DATA_W DriverInfoData
);