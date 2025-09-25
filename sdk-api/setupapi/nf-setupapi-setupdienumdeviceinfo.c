WINSETUPAPI BOOL SetupDiEnumDeviceInfo(
  [in]  HDEVINFO         DeviceInfoSet,
  [in]  DWORD            MemberIndex,
  [out] PSP_DEVINFO_DATA DeviceInfoData
);