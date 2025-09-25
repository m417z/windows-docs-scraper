WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameA(
  [in]            DWORD  HwProfile,
  [out]           PSTR   FriendlyName,
  [in]            DWORD  FriendlyNameSize,
  [out, optional] PDWORD RequiredSize
);