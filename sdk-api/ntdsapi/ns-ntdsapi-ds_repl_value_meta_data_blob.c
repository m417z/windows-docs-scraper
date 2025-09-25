typedef struct _DS_REPL_VALUE_META_DATA_BLOB {
  DWORD    oszAttributeName;
  DWORD    oszObjectDn;
  DWORD    cbData;
  DWORD    obData;
  FILETIME ftimeDeleted;
  FILETIME ftimeCreated;
  DWORD    dwVersion;
  FILETIME ftimeLastOriginatingChange;
  UUID     uuidLastOriginatingDsaInvocationID;
  USN      usnOriginatingChange;
  USN      usnLocalChange;
  DWORD    oszLastOriginatingDsaDN;
} DS_REPL_VALUE_META_DATA_BLOB;