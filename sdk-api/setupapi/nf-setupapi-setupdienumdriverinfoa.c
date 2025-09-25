WINSETUPAPI BOOL SetupDiEnumDriverInfoA(
  [in]           HDEVINFO           DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA   DeviceInfoData,
  [in]           DWORD              DriverType,
  [in]           DWORD              MemberIndex,
  [out]          PSP_DRVINFO_DATA_A DriverInfoData
);