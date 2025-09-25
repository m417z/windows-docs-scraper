WINSETUPAPI HDEVINFO SetupDiGetClassDevsA(
  const GUID *ClassGuid,
  PCSTR      Enumerator,
  HWND       hwndParent,
  DWORD      Flags
);