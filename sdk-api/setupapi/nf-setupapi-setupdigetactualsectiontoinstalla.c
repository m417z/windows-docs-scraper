WINSETUPAPI BOOL SetupDiGetActualSectionToInstallA(
  [in]            HINF   InfHandle,
  [in]            PCSTR  InfSectionName,
  [out, optional] PSTR   InfSectionWithExt,
  [in]            DWORD  InfSectionWithExtSize,
  [out, optional] PDWORD RequiredSize,
  [out, optional] PSTR   *Extension
);