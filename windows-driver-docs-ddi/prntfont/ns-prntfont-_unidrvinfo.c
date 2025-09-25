typedef struct _UNIDRVINFO {
  DWORD dwSize;
  DWORD flGenFlags;
  WORD  wType;
  WORD  fCaps;
  WORD  wXRes;
  WORD  wYRes;
  short sYAdjust;
  short sYMoved;
  WORD  wPrivateData;
  short sShift;
  INVOC SelectFont;
  INVOC UnSelectFont;
  WORD  wReserved[4];
} UNIDRVINFO, *PUNIDRVINFO;