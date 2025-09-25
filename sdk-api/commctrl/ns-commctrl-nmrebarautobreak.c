typedef struct tagNMREBARAUTOBREAK {
  NMHDR  hdr;
  UINT   uBand;
  UINT   wID;
  LPARAM lParam;
  UINT   uMsg;
  UINT   fStyleCurrent;
  BOOL   fAutoBreak;
} NMREBARAUTOBREAK, *LPNMREBARAUTOBREAK;