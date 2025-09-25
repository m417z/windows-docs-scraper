typedef struct _DS_REPL_ATTR_META_DATA {
  LPWSTR   pszAttributeName;
  DWORD    dwVersion;
  FILETIME ftimeLastOriginatingChange;
  UUID     uuidLastOriginatingDsaInvocationID;
  USN      usnOriginatingChange;
  USN      usnLocalChange;
} DS_REPL_ATTR_META_DATA;