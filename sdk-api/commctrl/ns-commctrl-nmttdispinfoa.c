typedef struct tagNMTTDISPINFOA {
  NMHDR     hdr;
  LPSTR     lpszText;
  char      szText[80];
  HINSTANCE hinst;
  UINT      uFlags;
  LPARAM    lParam;
} NMTTDISPINFOA, *LPNMTTDISPINFOA;