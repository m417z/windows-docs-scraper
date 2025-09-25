WINSETUPAPI BOOL SetupDiClassNameFromGuidA(
  [in]            const GUID *ClassGuid,
  [out]           PSTR       ClassName,
  [in]            DWORD      ClassNameSize,
  [out, optional] PDWORD     RequiredSize
);