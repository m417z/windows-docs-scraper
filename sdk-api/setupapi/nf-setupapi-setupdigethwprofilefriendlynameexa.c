WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameExA(
  [in]            DWORD  HwProfile,
  [out]           PSTR   FriendlyName,
  [in]            DWORD  FriendlyNameSize,
  [out, optional] PDWORD RequiredSize,
  [in, optional]  PCSTR  MachineName,
                  PVOID  Reserved
);