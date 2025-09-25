typedef struct _DS_REPL_NEIGHBORW_BLOB {
  DWORD    oszNamingContext;
  DWORD    oszSourceDsaDN;
  DWORD    oszSourceDsaAddress;
  DWORD    oszAsyncIntersiteTransportDN;
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
} DS_REPL_NEIGHBORW_BLOB;