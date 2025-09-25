typedef struct tagSCROLLBARINFO {
  DWORD cbSize;
  RECT  rcScrollBar;
  int   dxyLineButton;
  int   xyThumbTop;
  int   xyThumbBottom;
  int   reserved;
  DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
} SCROLLBARINFO, *PSCROLLBARINFO, *LPSCROLLBARINFO;