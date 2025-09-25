typedef struct _STORAGE_TEMPERATURE_INFO {
  USHORT  Index;
  SHORT   Temperature;
  SHORT   OverThreshold;
  SHORT   UnderThreshold;
  BOOLEAN OverThresholdChangable;
  BOOLEAN UnderThresholdChangable;
  BOOLEAN EventGenerated;
  UCHAR   Reserved0;
  ULONG   Reserved1;
} STORAGE_TEMPERATURE_INFO, *PSTORAGE_TEMPERATURE_INFO;