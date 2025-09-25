typedef struct tagNMPGHOTITEM {
  NMHDR hdr;
  int   idOld;
  int   idNew;
  DWORD dwFlags;
} NMPGHOTITEM, *LPNMPGHOTITEM;