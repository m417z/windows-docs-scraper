BOOL DiUninstallDriverA(
  [in, optional]  HWND   hwndParent,
  [in]            LPCSTR InfPath,
  [in]            DWORD  Flags,
  [out, optional] PBOOL  NeedReboot
);