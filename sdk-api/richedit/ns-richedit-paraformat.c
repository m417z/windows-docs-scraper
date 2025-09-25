typedef struct _paraformat {
  UINT  cbSize;
  DWORD dwMask;
  WORD  wNumbering;
  union {
    WORD wReserved;
    WORD wEffects;
  };
  LONG  dxStartIndent;
  LONG  dxRightIndent;
  LONG  dxOffset;
  WORD  wAlignment;
  SHORT cTabCount;
  LONG  rgxTabs[MAX_TAB_STOPS];
} PARAFORMAT;