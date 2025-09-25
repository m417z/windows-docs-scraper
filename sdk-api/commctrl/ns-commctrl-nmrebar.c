typedef struct tagNMREBAR {
  NMHDR  hdr;
  DWORD  dwMask;
  UINT   uBand;
  UINT   fStyle;
  UINT   wID;
  LPARAM lParam;
} NMREBAR, *LPNMREBAR;