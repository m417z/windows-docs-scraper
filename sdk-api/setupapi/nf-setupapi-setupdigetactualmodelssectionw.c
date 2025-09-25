WINSETUPAPI BOOL SetupDiGetActualModelsSectionW(
  [in]            PINFCONTEXT          Context,
  [in, optional]  PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
  [out, optional] PWSTR                InfSectionWithExt,
  [in]            DWORD                InfSectionWithExtSize,
  [out, optional] PDWORD               RequiredSize,
                  PVOID                Reserved
);