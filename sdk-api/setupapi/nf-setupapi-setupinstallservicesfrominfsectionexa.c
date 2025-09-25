WINSETUPAPI BOOL SetupInstallServicesFromInfSectionExA(
  [in] HINF             InfHandle,
  [in] PCSTR            SectionName,
  [in] DWORD            Flags,
  [in] HDEVINFO         DeviceInfoSet,
  [in] PSP_DEVINFO_DATA DeviceInfoData,
       PVOID            Reserved1,
       PVOID            Reserved2
);