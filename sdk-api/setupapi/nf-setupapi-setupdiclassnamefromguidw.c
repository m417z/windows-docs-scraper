WINSETUPAPI BOOL SetupDiClassNameFromGuidW(
  [in]            const GUID *ClassGuid,
  [out]           PWSTR      ClassName,
  [in]            DWORD      ClassNameSize,
  [out, optional] PDWORD     RequiredSize
);