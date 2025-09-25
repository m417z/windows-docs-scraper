WINSETUPAPI BOOL SetupDiInstallClassA(
  [in, optional] HWND     hwndParent,
  [in]           PCSTR    InfFileName,
  [in]           DWORD    Flags,
  [in, optional] HSPFILEQ FileQueue
);