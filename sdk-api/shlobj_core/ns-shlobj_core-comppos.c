typedef struct _tagCOMPPOS {
  DWORD dwSize;
  int   iLeft;
  int   iTop;
  DWORD dwWidth;
  DWORD dwHeight;
  int   izIndex;
  BOOL  fCanResize;
  BOOL  fCanResizeX;
  BOOL  fCanResizeY;
  int   iPreferredLeftPercent;
  int   iPreferredTopPercent;
} COMPPOS;