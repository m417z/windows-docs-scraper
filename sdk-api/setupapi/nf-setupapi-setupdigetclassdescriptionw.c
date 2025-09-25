WINSETUPAPI BOOL SetupDiGetClassDescriptionW(
  [in]            const GUID *ClassGuid,
  [out]           PWSTR      ClassDescription,
  [in]            DWORD      ClassDescriptionSize,
  [out, optional] PDWORD     RequiredSize
);