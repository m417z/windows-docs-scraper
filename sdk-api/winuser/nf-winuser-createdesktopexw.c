HDESK CreateDesktopExW(
  [in]           LPCWSTR               lpszDesktop,
                 LPCWSTR               lpszDevice,
                 DEVMODEW              *pDevmode,
  [in]           DWORD                 dwFlags,
  [in]           ACCESS_MASK           dwDesiredAccess,
  [in, optional] LPSECURITY_ATTRIBUTES lpsa,
  [in]           ULONG                 ulHeapSize,
                 PVOID                 pvoid
);