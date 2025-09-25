typedef struct _DS_REPL_ATTR_VALUE_META_DATA_2 {
  DWORD                     cNumEntries;
  DWORD                     dwEnumerationContext;
#if ...
  DS_REPL_VALUE_META_DATA_2 rgMetaData[];
#else
  DS_REPL_VALUE_META_DATA_2 rgMetaData[1];
#endif
} DS_REPL_ATTR_VALUE_META_DATA_2;