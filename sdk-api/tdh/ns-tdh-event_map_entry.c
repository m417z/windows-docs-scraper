typedef struct _EVENT_MAP_ENTRY {
  ULONG OutputOffset;
  union {
    ULONG Value;
    ULONG InputOffset;
  };
} EVENT_MAP_ENTRY;