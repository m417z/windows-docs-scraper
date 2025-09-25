typedef struct {
  GUID  guid;
  DWORD guidType;
#if ...
  CHAR  *pName;
#else
  LPSTR pName;
#endif
} DS_SCHEMA_GUID_MAPA, *PDS_SCHEMA_GUID_MAPA;