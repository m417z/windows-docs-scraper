typedef struct tagNMCHAR {
  NMHDR hdr;
  UINT  ch;
  DWORD dwItemPrev;
  DWORD dwItemNext;
} NMCHAR, *LPNMCHAR;