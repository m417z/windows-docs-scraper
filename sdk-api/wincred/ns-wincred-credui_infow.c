typedef struct _CREDUI_INFOW {
  DWORD   cbSize;
  HWND    hwndParent;
  PCWSTR  pszMessageText;
  PCWSTR  pszCaptionText;
  HBITMAP hbmBanner;
} CREDUI_INFOW, *PCREDUI_INFOW;