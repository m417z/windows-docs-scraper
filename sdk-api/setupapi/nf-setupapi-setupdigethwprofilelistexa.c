WINSETUPAPI BOOL SetupDiGetHwProfileListExA(
  [out]           PDWORD HwProfileList,
  [in]            DWORD  HwProfileListSize,
  [out]           PDWORD RequiredSize,
  [out, optional] PDWORD CurrentlyActiveIndex,
  [in, optional]  PCSTR  MachineName,
                  PVOID  Reserved
);