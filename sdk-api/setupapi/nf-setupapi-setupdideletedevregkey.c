WINSETUPAPI BOOL SetupDiDeleteDevRegKey(
  [in] HDEVINFO         DeviceInfoSet,
  [in] PSP_DEVINFO_DATA DeviceInfoData,
  [in] DWORD            Scope,
  [in] DWORD            HwProfile,
  [in] DWORD            KeyType
);