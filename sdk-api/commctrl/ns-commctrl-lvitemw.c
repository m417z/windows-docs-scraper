typedef struct tagLVITEMW {
  UINT   mask;
  int    iItem;
  int    iSubItem;
  UINT   state;
  UINT   stateMask;
  LPWSTR pszText;
  int    cchTextMax;
  int    iImage;
  LPARAM lParam;
  int    iIndent;
  int    iGroupId;
  UINT   cColumns;
  PUINT  puColumns;
  int    *piColFmt;
  int    iGroup;
} LVITEMW, *LPLVITEMW;