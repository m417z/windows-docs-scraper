typedef struct _DXGK_NATIVE_FENCE_LOG_HEADER {
  union {
    struct {
      UINT32 FirstFreeEntryIndex;
      UINT32 WraparoundCount;
    };
    ULARGE_INTEGER AtomicWraparoundAndEntryIndex;
  };
  DXGK_NATIVE_FENCE_LOG_TYPE Type;
  UINT64                     NumberOfEntries;
  UINT64                     Reserved[2];
} DXGK_NATIVE_FENCE_LOG_HEADER;