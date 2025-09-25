WINSETUPAPI BOOL SetupDiClassGuidsFromNameExA(
  [in]           PCSTR  ClassName,
  [out]          LPGUID ClassGuidList,
  [in]           DWORD  ClassGuidListSize,
  [out]          PDWORD RequiredSize,
  [in, optional] PCSTR  MachineName,
                 PVOID  Reserved
);