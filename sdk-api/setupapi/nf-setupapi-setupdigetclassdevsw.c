WINSETUPAPI HDEVINFO SetupDiGetClassDevsW(
  [in, optional] const GUID *ClassGuid,
  [in, optional] PCWSTR     Enumerator,
  [in, optional] HWND       hwndParent,
  [in]           DWORD      Flags
);