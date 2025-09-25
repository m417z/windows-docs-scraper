typedef struct _DS_REPL_CURSOR_BLOB {
  UUID     uuidSourceDsaInvocationID;
  USN      usnAttributeFilter;
  FILETIME ftimeLastSyncSuccess;
  DWORD    oszSourceDsaDN;
} DS_REPL_CURSOR_BLOB;