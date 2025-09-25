typedef struct _CI_STATE {
  DWORD cbStruct;
  DWORD cWordList;
  DWORD cPersistentIndex;
  DWORD cQueries;
  DWORD cDocuments;
  DWORD cFreshTest;
  DWORD dwMergeProgress;
  DWORD eState;
  DWORD cFilteredDocuments;
  DWORD cTotalDocuments;
  DWORD cPendingScans;
  DWORD dwIndexSize;
  DWORD cUniqueKeys;
  DWORD cSecQDocuments;
  DWORD dwPropCacheSize;
} CI_STATE;