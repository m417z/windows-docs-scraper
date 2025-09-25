WINSETUPAPI BOOL SetupDiGetINFClassW(
  [in]            PCWSTR InfName,
  [out]           LPGUID ClassGuid,
  [out]           PWSTR  ClassName,
  [in]            DWORD  ClassNameSize,
  [out, optional] PDWORD RequiredSize
);