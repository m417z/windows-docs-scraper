WINSETUPAPI BOOL SetupDiBuildClassInfoList(
  [in]            DWORD  Flags,
  [out, optional] LPGUID ClassGuidList,
  [in]            DWORD  ClassGuidListSize,
  [out]           PDWORD RequiredSize
);