typedef struct _DS_REPL_VALUE_META_DATA_BLOB_EXT {
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
  DWORD    dwUserIdentifier;
  DWORD    dwPriorLinkState;
  DWORD    dwCurrentLinkState;
} DS_REPL_VALUE_META_DATA_BLOB_EXT;