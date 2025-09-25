typedef struct {
  NMHDR     hdr;
  DWORD     dwMask;
  int       idCommand;
  DWORD_PTR lParam;
  int       iImage;
  LPWSTR    pszText;
  int       cchText;
} NMTBDISPINFOW, *LPNMTBDISPINFOW;