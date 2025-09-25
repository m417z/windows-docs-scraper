WINSETUPAPI BOOL SetupDiClassGuidsFromNameA(
  [in]  PCSTR  ClassName,
  [out] LPGUID ClassGuidList,
  [in]  DWORD  ClassGuidListSize,
  [out] PDWORD RequiredSize
);