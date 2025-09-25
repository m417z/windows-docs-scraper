typedef struct tagNMLVEMPTYMARKUP {
  NMHDR hdr;
  DWORD dwFlags;
  WCHAR szMarkup[L_MAX_URL_LENGTH];
} NMLVEMPTYMARKUP;