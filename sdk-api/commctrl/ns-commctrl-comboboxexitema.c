typedef struct tagCOMBOBOXEXITEMA {
  UINT    mask;
  INT_PTR iItem;
  LPSTR   pszText;
  int     cchTextMax;
  int     iImage;
  int     iSelectedImage;
  int     iOverlay;
  int     iIndent;
  LPARAM  lParam;
} COMBOBOXEXITEMA, *PCOMBOBOXEXITEMA;