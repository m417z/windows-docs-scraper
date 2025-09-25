typedef struct {
  int   iNextSample;
  DWORD dwLastScroll;
  BOOL  bFull;
  POINT pts[NUM_POINTS];
  DWORD dwTimes[NUM_POINTS];
} AUTO_SCROLL_DATA;