typedef struct {
  GUID   guid;
  DWORD  guidType;
#if ...
  WCHAR  *pName;
#else
  LPWSTR pName;
#endif
} DS_SCHEMA_GUID_MAPW, *PDS_SCHEMA_GUID_MAPW;