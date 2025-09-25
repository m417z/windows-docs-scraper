WINSETUPAPI BOOL SetupDiGetHwProfileList(
  [out]           PDWORD HwProfileList,
  [in]            DWORD  HwProfileListSize,
  [out]           PDWORD RequiredSize,
  [out, optional] PDWORD CurrentlyActiveIndex
);