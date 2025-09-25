typedef struct {
  NMHDR hdr;
  BOOL  fChanged;
  int   iNewSelection;
  char  szText[CBEMAXSTRLEN];
  int   iWhy;
} NMCBEENDEDITA, *LPNMCBEENDEDITA, *PNMCBEENDEDITA;