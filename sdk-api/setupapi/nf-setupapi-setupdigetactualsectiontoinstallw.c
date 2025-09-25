WINSETUPAPI BOOL SetupDiGetActualSectionToInstallW(
  [in]            HINF   InfHandle,
  [in]            PCWSTR InfSectionName,
  [out, optional] PWSTR  InfSectionWithExt,
  [in]            DWORD  InfSectionWithExtSize,
  [out, optional] PDWORD RequiredSize,
  [out, optional] PWSTR  *Extension
);