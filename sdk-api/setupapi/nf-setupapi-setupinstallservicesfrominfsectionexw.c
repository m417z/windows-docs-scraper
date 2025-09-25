WINSETUPAPI BOOL SetupInstallServicesFromInfSectionExW(
  [in] HINF             InfHandle,
  [in] PCWSTR           SectionName,
  [in] DWORD            Flags,
  [in] HDEVINFO         DeviceInfoSet,
  [in] PSP_DEVINFO_DATA DeviceInfoData,
       PVOID            Reserved1,
       PVOID            Reserved2
);