typedef struct _WLX_DESKTOP {
  DWORD Size;
  DWORD Flags;
  HDESK hDesktop;
  PWSTR pszDesktopName;
} WLX_DESKTOP, *PWLX_DESKTOP;