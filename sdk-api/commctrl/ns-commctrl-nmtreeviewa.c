typedef struct tagNMTREEVIEWA {
  NMHDR   hdr;
  UINT    action;
  TVITEMA itemOld;
  TVITEMA itemNew;
  POINT   ptDrag;
} NMTREEVIEWA, *LPNMTREEVIEWA;