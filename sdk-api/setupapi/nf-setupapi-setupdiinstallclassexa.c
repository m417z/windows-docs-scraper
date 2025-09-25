WINSETUPAPI BOOL SetupDiInstallClassExA(
  [in, optional] HWND       hwndParent,
  [in, optional] PCSTR      InfFileName,
  [in]           DWORD      Flags,
  [in, optional] HSPFILEQ   FileQueue,
  [in, optional] const GUID *InterfaceClassGuid,
                 PVOID      Reserved1,
                 PVOID      Reserved2
);