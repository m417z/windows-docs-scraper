typedef struct {
  DWORD     cbStruct;
  DWORD     dwFlags;
  HINSTANCE hInstance;
  LONG      offsetQuery;
  LONG      iColumns;
  DWORD     dwReserved;
  DSCOLUMN  aColumns[1];
} DSQUERYPARAMS, *LPDSQUERYPARAMS;