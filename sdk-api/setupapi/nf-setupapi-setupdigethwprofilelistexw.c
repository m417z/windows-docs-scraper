WINSETUPAPI BOOL SetupDiGetHwProfileListExW(
  [out]           PDWORD HwProfileList,
  [in]            DWORD  HwProfileListSize,
  [out]           PDWORD RequiredSize,
  [out, optional] PDWORD CurrentlyActiveIndex,
  [in, optional]  PCWSTR MachineName,
                  PVOID  Reserved
);