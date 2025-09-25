WINSETUPAPI HDEVINFO SetupDiGetClassDevsExW(
  [in, optional] const GUID *ClassGuid,
  [in, optional] PCWSTR     Enumerator,
  [in, optional] HWND       hwndParent,
  [in]           DWORD      Flags,
  [in, optional] HDEVINFO   DeviceInfoSet,
  [in, optional] PCWSTR     MachineName,
                 PVOID      Reserved
);