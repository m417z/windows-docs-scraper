WINSETUPAPI BOOL SetupDiGetClassDescriptionExA(
  [in]            const GUID *ClassGuid,
  [out]           PSTR       ClassDescription,
  [in]            DWORD      ClassDescriptionSize,
  [out, optional] PDWORD     RequiredSize,
  [in, optional]  PCSTR      MachineName,
                  PVOID      Reserved
);