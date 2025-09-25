typedef struct {
  NMHDR hdr;
  WORD  fwKeys;
  RECT  rcParent;
  int   iDir;
  int   iXpos;
  int   iYpos;
  int   iScroll;
} NMPGSCROLL, *LPNMPGSCROLL;