typedef struct {
  NMHDR hdr;
  int   iItemid;
  char  szText[CBEMAXSTRLEN];
} NMCBEDRAGBEGINA, *LPNMCBEDRAGBEGINA, *PNMCBEDRAGBEGINA;