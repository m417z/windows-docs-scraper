typedef struct tagNMREBARCHEVRON {
  NMHDR  hdr;
  UINT   uBand;
  UINT   wID;
  LPARAM lParam;
  RECT   rc;
  LPARAM lParamNM;
} NMREBARCHEVRON, *LPNMREBARCHEVRON;