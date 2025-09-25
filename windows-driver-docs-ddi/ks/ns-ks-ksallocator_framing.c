typedef struct {
  union {
    ULONG OptionsFlags;
    ULONG RequirementsFlags;
  };
#if ...
  POOL_TYPE PoolType;
#else
  ULONG     PoolType;
#endif
  ULONG     Frames;
  ULONG     FrameSize;
  union {
    ULONG FileAlignment;
    LONG  FramePitch;
  };
  ULONG     Reserved;
} KSALLOCATOR_FRAMING, *PKSALLOCATOR_FRAMING;