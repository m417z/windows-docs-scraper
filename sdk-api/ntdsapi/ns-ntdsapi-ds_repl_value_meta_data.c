typedef struct _DS_REPL_VALUE_META_DATA {
  LPWSTR   pszAttributeName;
  LPWSTR   pszObjectDn;
  DWORD    cbData;
#if ...
  BYTE     *pbData;
#else
  BYTE     *pbData;
#endif
  FILETIME ftimeDeleted;
  FILETIME ftimeCreated;
  DWORD    dwVersion;
  FILETIME ftimeLastOriginatingChange;
  UUID     uuidLastOriginatingDsaInvocationID;
  USN      usnOriginatingChange;
  USN      usnLocalChange;
} DS_REPL_VALUE_META_DATA;