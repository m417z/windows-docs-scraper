typedef struct _DS_REPL_KCC_DSA_FAILUREW {
  LPWSTR   pszDsaDN;
  UUID     uuidDsaObjGuid;
  FILETIME ftimeFirstFailure;
  DWORD    cNumFailures;
  DWORD    dwLastResult;
} DS_REPL_KCC_DSA_FAILUREW;