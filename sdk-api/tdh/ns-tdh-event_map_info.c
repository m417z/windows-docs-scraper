typedef struct _EVENT_MAP_INFO {
  ULONG           NameOffset;
  MAP_FLAGS       Flag;
  ULONG           EntryCount;
  union {
    MAP_VALUETYPE MapEntryValueType;
    ULONG         FormatStringOffset;
  };
  EVENT_MAP_ENTRY MapEntryArray[ANYSIZE_ARRAY];
} EVENT_MAP_INFO;