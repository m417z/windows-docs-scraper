WINSETUPAPI BOOL SetupDiInstallClassW(
  [in, optional] HWND     hwndParent,
  [in]           PCWSTR   InfFileName,
  [in]           DWORD    Flags,
  [in, optional] HSPFILEQ FileQueue
);