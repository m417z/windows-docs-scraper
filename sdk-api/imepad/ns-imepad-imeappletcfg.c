typedef struct tagAPPLETCFG {
  DWORD  dwConfig;
  WCHAR  wchTitle[MAX_APPLETTITLE];
  WCHAR  wchTitleFontFace[MAX_FONTFACE];
  DWORD  dwCharSet;
  INT    iCategory;
  HICON  hIcon;
  LANGID langID;
  WORD   dummy;
  LPARAM lReserved1;
} IMEAPPLETCFG, *LPIMEAPPLETCFG;