typedef struct _DXGK_SCHEDULING_LOG_HEADER {
  union {
    struct {
      UINT32 FirstFreeEntryIndex;
      UINT32 WraparoundCount;
    };
    ULARGE_INTEGER AtomicWraparoundAndEntryIndex;
  };
  UINT64 NumberOfEntries;
  UINT64 Reserved[2];
} DXGK_SCHEDULING_LOG_HEADER;