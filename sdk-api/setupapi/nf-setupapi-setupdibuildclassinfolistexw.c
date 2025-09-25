WINSETUPAPI BOOL SetupDiBuildClassInfoListExW(
  [in]            DWORD  Flags,
  [out, optional] LPGUID ClassGuidList,
  [in]            DWORD  ClassGuidListSize,
  [out]           PDWORD RequiredSize,
  [in, optional]  PCWSTR MachineName,
                  PVOID  Reserved
);