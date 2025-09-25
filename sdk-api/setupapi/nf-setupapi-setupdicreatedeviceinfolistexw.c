WINSETUPAPI HDEVINFO SetupDiCreateDeviceInfoListExW(
  [in, optional] const GUID *ClassGuid,
  [in, optional] HWND       hwndParent,
  [in, optional] PCWSTR     MachineName,
                 PVOID      Reserved
);