typedef struct _DS_REPL_ATTR_META_DATA_BLOB {
  DWORD    oszAttributeName;
  DWORD    dwVersion;
  FILETIME ftimeLastOriginatingChange;
  UUID     uuidLastOriginatingDsaInvocationID;
  USN      usnOriginatingChange;
  USN      usnLocalChange;
  DWORD    oszLastOriginatingDsaDN;
} DS_REPL_ATTR_META_DATA_BLOB;