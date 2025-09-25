typedef struct tagNMTBSAVE {
  NMHDR    hdr;
  DWORD    *pData;
  DWORD    *pCurrent;
  UINT     cbData;
  int      iItem;
  int      cButtons;
  TBBUTTON tbButton;
} NMTBSAVE, *LPNMTBSAVE;