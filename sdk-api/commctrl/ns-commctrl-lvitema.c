typedef struct tagLVITEMA {
  UINT   mask;
  int    iItem;
  int    iSubItem;
  UINT   state;
  UINT   stateMask;
  LPSTR  pszText;
  int    cchTextMax;
  int    iImage;
  LPARAM lParam;
  int    iIndent;
  int    iGroupId;
  UINT   cColumns;
  PUINT  puColumns;
  int    *piColFmt;
  int    iGroup;
} LVITEMA, *LPLVITEMA;