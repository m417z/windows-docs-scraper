typedef struct tagPROPPAGEINFO {
  ULONG    cb;
  LPOLESTR pszTitle;
  SIZE     size;
  LPOLESTR pszDocString;
  LPOLESTR pszHelpFile;
  DWORD    dwHelpContext;
} PROPPAGEINFO, *LPPROPPAGEINFO;