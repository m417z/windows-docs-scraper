typedef struct tagIMEAPPLETUI {
  HWND   hwnd;
  DWORD  dwStyle;
  INT    width;
  INT    height;
  INT    minWidth;
  INT    minHeight;
  INT    maxWidth;
  INT    maxHeight;
  LPARAM lReserved1;
  LPARAM lReserved2;
} IMEAPPLETUI, *LPIMEAPPLETUI;