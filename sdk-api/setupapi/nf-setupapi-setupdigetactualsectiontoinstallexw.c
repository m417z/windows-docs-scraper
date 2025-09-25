WINSETUPAPI BOOL SetupDiGetActualSectionToInstallExW(
  [in]            HINF                 InfHandle,
  [in]            PCWSTR               InfSectionName,
  [in, optional]  PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
  [out, optional] PWSTR                InfSectionWithExt,
  [in]            DWORD                InfSectionWithExtSize,
  [out, optional] PDWORD               RequiredSize,
  [out, optional] PWSTR                *Extension,
                  PVOID                Reserved
);