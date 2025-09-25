typedef struct {
  NMHDR     hdr;
  DWORD     dwMask;
  int       idCommand;
  DWORD_PTR lParam;
  int       iImage;
  LPSTR     pszText;
  int       cchText;
} NMTBDISPINFOA, *LPNMTBDISPINFOA;