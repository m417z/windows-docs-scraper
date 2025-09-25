typedef struct _COMPROPSHEETUI {
  WORD           cbSize;
  WORD           Flags;
  HINSTANCE      hInstCaller;
  LPTSTR         pCallerName;
  ULONG_PTR      UserData;
  LPTSTR         pHelpFile;
  _CPSUICALLBACK pfnCallBack;
  POPTITEM       pOptItem;
  PDLGPAGE       pDlgPage;
  WORD           cOptItem;
  WORD           cDlgPage;
  ULONG_PTR      IconID;
  LPTSTR         pOptItemName;
  WORD           CallerVersion;
  WORD           OptItemVersion;
  ULONG_PTR      dwReserved[4];
} COMPROPSHEETUI, *PCOMPROPSHEETUI;