typedef struct _DS_REPL_OBJ_META_DATA_2 {
  DWORD                    cNumEntries;
  DWORD                    dwReserved;
#if ...
  DS_REPL_ATTR_META_DATA_2 rgMetaData[];
#else
  DS_REPL_ATTR_META_DATA_2 rgMetaData[1];
#endif
} DS_REPL_OBJ_META_DATA_2;