typedef struct _DS_REPL_ATTR_VALUE_META_DATA {
  DWORD                   cNumEntries;
  DWORD                   dwEnumerationContext;
#if ...
  DS_REPL_VALUE_META_DATA rgMetaData[];
#else
  DS_REPL_VALUE_META_DATA rgMetaData[1];
#endif
} DS_REPL_ATTR_VALUE_META_DATA;