typedef struct _DS_REPL_ATTR_META_DATA_2 {
  LPWSTR   pszAttributeName;
  DWORD    dwVersion;
  FILETIME ftimeLastOriginatingChange;
  UUID     uuidLastOriginatingDsaInvocationID;
  USN      usnOriginatingChange;
  USN      usnLocalChange;
  LPWSTR   pszLastOriginatingDsaDN;
} DS_REPL_ATTR_META_DATA_2;