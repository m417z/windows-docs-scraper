typedef struct _IDE_ACCESS_RANGE {
  IDE_PHYSICAL_ADDRESS RangeStart;
  IDE_PHYSICAL_ADDRESS PhysicalRangeStart;
  ULONG                RangeLength;
  BOOLEAN              InMemory;
  UCHAR                Bar;
} IDE_ACCESS_RANGE, *PIDE_ACCESS_RANGE;