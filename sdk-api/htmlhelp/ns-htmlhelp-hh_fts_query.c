typedef struct tagHH_FTS_QUERY {
  int     cbStruct;
  BOOL    fUniCodeStrings;
  LPCTSTR pszSearchQuery;
  LONG    iProximity;
  BOOL    fStemmedSearch;
  BOOL    fTitleOnly;
  BOOL    fExecute;
  LPCTSTR pszWindow;
} HH_FTS_QUERY;