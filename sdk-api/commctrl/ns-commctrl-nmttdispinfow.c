typedef struct tagNMTTDISPINFOW {
  NMHDR     hdr;
  LPWSTR    lpszText;
  WCHAR     szText[80];
  HINSTANCE hinst;
  UINT      uFlags;
  LPARAM    lParam;
} NMTTDISPINFOW, *LPNMTTDISPINFOW;