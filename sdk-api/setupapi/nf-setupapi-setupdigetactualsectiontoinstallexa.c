WINSETUPAPI BOOL SetupDiGetActualSectionToInstallExA(
  [in]            HINF                 InfHandle,
  [in]            PCSTR                InfSectionName,
  [in, optional]  PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
  [out, optional] PSTR                 InfSectionWithExt,
  [in]            DWORD                InfSectionWithExtSize,
  [out, optional] PDWORD               RequiredSize,
  [out, optional] PSTR                 *Extension,
                  PVOID                Reserved
);