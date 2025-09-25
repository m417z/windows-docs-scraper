HDESK CreateDesktopExA(
  [in]           LPCSTR                lpszDesktop,
                 LPCSTR                lpszDevice,
                 DEVMODEA              *pDevmode,
  [in]           DWORD                 dwFlags,
  [in]           ACCESS_MASK           dwDesiredAccess,
  [in, optional] LPSECURITY_ATTRIBUTES lpsa,
  [in]           ULONG                 ulHeapSize,
                 PVOID                 pvoid
);