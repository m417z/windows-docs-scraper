WINSETUPAPI BOOL SetupDiGetINFClassA(
  [in]            PCSTR  InfName,
  [out]           LPGUID ClassGuid,
  [out]           PSTR   ClassName,
  [in]            DWORD  ClassNameSize,
  [out, optional] PDWORD RequiredSize
);