WINSETUPAPI HDEVINFO SetupDiGetClassDevsExA(
  [in, optional] const GUID *ClassGuid,
  [in, optional] PCSTR      Enumerator,
  [in, optional] HWND       hwndParent,
  [in]           DWORD      Flags,
  [in, optional] HDEVINFO   DeviceInfoSet,
  [in, optional] PCSTR      MachineName,
                 PVOID      Reserved
);