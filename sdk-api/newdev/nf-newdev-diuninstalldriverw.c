BOOL DiUninstallDriverW(
  [in, optional]  HWND    hwndParent,
  [in]            LPCWSTR InfPath,
  [in]            DWORD   Flags,
  [out, optional] PBOOL   NeedReboot
);