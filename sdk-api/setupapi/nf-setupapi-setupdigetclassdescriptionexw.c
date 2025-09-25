WINSETUPAPI BOOL SetupDiGetClassDescriptionExW(
  [in]            const GUID *ClassGuid,
  [out]           PWSTR      ClassDescription,
  [in]            DWORD      ClassDescriptionSize,
  [out, optional] PDWORD     RequiredSize,
  [in, optional]  PCWSTR     MachineName,
                  PVOID      Reserved
);