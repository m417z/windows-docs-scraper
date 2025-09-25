WINSETUPAPI BOOL SetupDiClassGuidsFromNameW(
  [in]  PCWSTR ClassName,
  [out] LPGUID ClassGuidList,
  [in]  DWORD  ClassGuidListSize,
  [out] PDWORD RequiredSize
);