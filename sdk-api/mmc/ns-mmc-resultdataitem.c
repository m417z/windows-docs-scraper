typedef struct _RESULTDATAITEM {
  DWORD       mask;
  BOOL        bScopeItem;
  HRESULTITEM itemID;
  int         nIndex;
  int         nCol;
  LPOLESTR    str;
  int         nImage;
  UINT        nState;
  LPARAM      lParam;
  int         iIndent;
} RESULTDATAITEM;