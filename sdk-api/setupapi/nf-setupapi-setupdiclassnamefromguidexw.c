WINSETUPAPI BOOL SetupDiClassNameFromGuidExW(
  [in]            const GUID *ClassGuid,
  [out]           PWSTR      ClassName,
  [in]            DWORD      ClassNameSize,
  [out, optional] PDWORD     RequiredSize,
  [in, optional]  PCWSTR     MachineName,
                  PVOID      Reserved
);