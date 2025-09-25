WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameW(
  [in]            DWORD  HwProfile,
  [out]           PWSTR  FriendlyName,
  [in]            DWORD  FriendlyNameSize,
  [out, optional] PDWORD RequiredSize
);