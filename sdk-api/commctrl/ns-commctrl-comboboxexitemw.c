typedef struct tagCOMBOBOXEXITEMW {
  UINT    mask;
  INT_PTR iItem;
  LPWSTR  pszText;
  int     cchTextMax;
  int     iImage;
  int     iSelectedImage;
  int     iOverlay;
  int     iIndent;
  LPARAM  lParam;
} COMBOBOXEXITEMW, *PCOMBOBOXEXITEMW;