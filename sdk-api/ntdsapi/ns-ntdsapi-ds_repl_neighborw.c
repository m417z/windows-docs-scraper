typedef struct _DS_REPL_NEIGHBORW {
  LPWSTR   pszNamingContext;
  LPWSTR   pszSourceDsaDN;
  LPWSTR   pszSourceDsaAddress;
  LPWSTR   pszAsyncIntersiteTransportDN;
  DWORD    dwReplicaFlags;
  DWORD    dwReserved;
  UUID     uuidNamingContextObjGuid;
  UUID     uuidSourceDsaObjGuid;
  UUID     uuidSourceDsaInvocationID;
  UUID     uuidAsyncIntersiteTransportObjGuid;
  USN      usnLastObjChangeSynced;
  USN      usnAttributeFilter;
  FILETIME ftimeLastSyncSuccess;
  FILETIME ftimeLastSyncAttempt;
  DWORD    dwLastSyncResult;
  DWORD    cNumConsecutiveSyncFailures;
} DS_REPL_NEIGHBORW;