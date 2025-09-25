typedef struct tagNMHEADERW {
  NMHDR   hdr;
  int     iItem;
  int     iButton;
  HDITEMW *pitem;
} NMHEADERW, *LPNMHEADERW;