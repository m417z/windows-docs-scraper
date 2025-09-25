typedef struct {
  GUID                      MemoryType;
  GUID                      BusType;
  ULONG                     MemoryFlags;
  ULONG                     BusFlags;
  ULONG                     Flags;
  ULONG                     Frames;
  union {
    ULONG FileAlignment;
    LONG  FramePitch;
  };
  ULONG                     MemoryTypeWeight;
  KS_FRAMING_RANGE          PhysicalRange;
  KS_FRAMING_RANGE_WEIGHTED FramingRange;
} KS_FRAMING_ITEM, *PKS_FRAMING_ITEM;