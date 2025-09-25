WINSETUPAPI BOOL SetupDiClassNameFromGuidExA(
  [in]            const GUID *ClassGuid,
  [out]           PSTR       ClassName,
  [in]            DWORD      ClassNameSize,
  [out, optional] PDWORD     RequiredSize,
  [in, optional]  PCSTR      MachineName,
                  PVOID      Reserved
);