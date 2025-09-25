typedef struct {
  NMHDR hdr;
  BOOL  fChanged;
  int   iNewSelection;
  WCHAR szText[CBEMAXSTRLEN];
  int   iWhy;
} NMCBEENDEDITW, *LPNMCBEENDEDITW, *PNMCBEENDEDITW;