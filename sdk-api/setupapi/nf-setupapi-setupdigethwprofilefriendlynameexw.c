WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameExW(
  [in]            DWORD  HwProfile,
  [out]           PWSTR  FriendlyName,
  [in]            DWORD  FriendlyNameSize,
  [out, optional] PDWORD RequiredSize,
  [in, optional]  PCWSTR MachineName,
                  PVOID  Reserved
);