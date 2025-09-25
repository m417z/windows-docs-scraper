WINSETUPAPI BOOL SetupDiClassGuidsFromNameExW(
  [in]           PCWSTR ClassName,
  [out]          LPGUID ClassGuidList,
  [in]           DWORD  ClassGuidListSize,
  [out]          PDWORD RequiredSize,
  [in, optional] PCWSTR MachineName,
                 PVOID  Reserved
);