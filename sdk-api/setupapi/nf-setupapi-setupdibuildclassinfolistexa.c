WINSETUPAPI BOOL SetupDiBuildClassInfoListExA(
  [in]            DWORD  Flags,
  [out, optional] LPGUID ClassGuidList,
  [in]            DWORD  ClassGuidListSize,
  [out]           PDWORD RequiredSize,
  [in, optional]  PCSTR  MachineName,
                  PVOID  Reserved
);