typedef struct tagNMITEMACTIVATE {
  NMHDR  hdr;
  int    iItem;
  int    iSubItem;
  UINT   uNewState;
  UINT   uOldState;
  UINT   uChanged;
  POINT  ptAction;
  LPARAM lParam;
  UINT   uKeyFlags;
} NMITEMACTIVATE, *LPNMITEMACTIVATE;