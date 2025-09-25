typedef struct _DS_REPL_CURSOR_3W {
  UUID     uuidSourceDsaInvocationID;
  USN      usnAttributeFilter;
  FILETIME ftimeLastSyncSuccess;
  LPWSTR   pszSourceDsaDN;
} DS_REPL_CURSOR_3W;