WINSETUPAPI HKEY SetupDiCreateDevRegKeyA(
  [in]           HDEVINFO         DeviceInfoSet,
  [in]           PSP_DEVINFO_DATA DeviceInfoData,
  [in]           DWORD            Scope,
  [in]           DWORD            HwProfile,
  [in]           DWORD            KeyType,
  [in, optional] HINF             InfHandle,
  [in, optional] PCSTR            InfSectionName
);