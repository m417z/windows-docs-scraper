WINSETUPAPI BOOL SetupDiGetActualModelsSectionA(
  [in]            PINFCONTEXT          Context,
  [in, optional]  PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
  [out, optional] PSTR                 InfSectionWithExt,
  [in]            DWORD                InfSectionWithExtSize,
  [out, optional] PDWORD               RequiredSize,
                  PVOID                Reserved
);