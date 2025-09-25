typedef struct _LPI_STATE_DESCRIPTOR {
  ULONG           Type;
  ULONG           Length;
  USHORT          UniqueId;
  UCHAR           Reserved[2];
  LPI_STATE_FLAGS Flags;
  GEN_ADDR        EntryTrigger;
  ULONG           Residency;
  ULONG           Latency;
  GEN_ADDR        ResidencyCounter;
  ULONGLONG       ResidencyCounterFrequency;
} LPI_STATE_DESCRIPTOR, *PLPI_STATE_DESCRIPTOR;