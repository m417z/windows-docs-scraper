typedef struct tagNMTREEVIEWW {
  NMHDR   hdr;
  UINT    action;
  TVITEMW itemOld;
  TVITEMW itemNew;
  POINT   ptDrag;
} NMTREEVIEWW, *LPNMTREEVIEWW;