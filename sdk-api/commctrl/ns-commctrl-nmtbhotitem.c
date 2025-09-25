typedef struct tagNMTBHOTITEM {
  NMHDR hdr;
  int   idOld;
  int   idNew;
  DWORD dwFlags;
} NMTBHOTITEM, *LPNMTBHOTITEM;