typedef struct _DS_REPL_OBJ_META_DATA {
  DWORD                  cNumEntries;
  DWORD                  dwReserved;
#if ...
  DS_REPL_ATTR_META_DATA rgMetaData[];
#else
  DS_REPL_ATTR_META_DATA rgMetaData[1];
#endif
} DS_REPL_OBJ_META_DATA;