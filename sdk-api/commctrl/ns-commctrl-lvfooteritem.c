typedef struct tagLVFOOTERITEM {
  UINT   mask;
  int    iItem;
  LPWSTR pszText;
  int    cchTextMax;
  UINT   state;
  UINT   stateMask;
} LVFOOTERITEM, *LPLVFOOTERITEM;