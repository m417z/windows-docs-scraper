typedef struct tagHH_POPUP {
  int       cbStruct;
  HINSTANCE hinst;
  UINT      idString;
  LPCTSTR   pszText;
  POINT     pt;
  COLORREF  clrForeground;
  COLORREF  clrBackground;
  RECT      rcMargins;
  LPCTSTR   pszFont;
} HH_POPUP;