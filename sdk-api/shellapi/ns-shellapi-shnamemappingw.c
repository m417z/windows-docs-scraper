typedef struct _SHNAMEMAPPINGW {
  LPWSTR pszOldPath;
  LPWSTR pszNewPath;
  int    cchOldPath;
  int    cchNewPath;
} SHNAMEMAPPINGW, *LPSHNAMEMAPPINGW;