WINSETUPAPI BOOL SetupDiGetClassDescriptionA(
  [in]            const GUID *ClassGuid,
  [out]           PSTR       ClassDescription,
  [in]            DWORD      ClassDescriptionSize,
  [out, optional] PDWORD     RequiredSize
);