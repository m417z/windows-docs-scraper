typedef struct _DS_REPL_ATTR_VALUE_META_DATA_EXT {
  DWORD                       cNumEntries;
  DWORD                       dwEnumerationContext;
#if ...
  DS_REPL_VALUE_META_DATA_EXT rgMetaData[];
#else
  DS_REPL_VALUE_META_DATA_EXT rgMetaData[1];
#endif
} DS_REPL_ATTR_VALUE_META_DATA_EXT;