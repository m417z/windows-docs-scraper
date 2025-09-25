typedef struct _CREDUI_INFOA {
  DWORD   cbSize;
  HWND    hwndParent;
  PCSTR   pszMessageText;
  PCSTR   pszCaptionText;
  HBITMAP hbmBanner;
} CREDUI_INFOA, *PCREDUI_INFOA;