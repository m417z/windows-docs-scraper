typedef struct tagNMTVCUSTOMDRAW {
  NMCUSTOMDRAW nmcd;
  COLORREF     clrText;
  COLORREF     clrTextBk;
  int          iLevel;
} NMTVCUSTOMDRAW, *LPNMTVCUSTOMDRAW;