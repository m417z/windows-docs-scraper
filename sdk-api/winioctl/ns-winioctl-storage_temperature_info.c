typedef struct _STORAGE_TEMPERATURE_INFO {
  WORD    Index;
  SHORT   Temperature;
  SHORT   OverThreshold;
  SHORT   UnderThreshold;
  BOOLEAN OverThresholdChangable;
  BOOLEAN UnderThresholdChangable;
  BOOLEAN EventGenerated;
  BYTE    Reserved0;
  DWORD   Reserved1;
} STORAGE_TEMPERATURE_INFO, *PSTORAGE_TEMPERATURE_INFO;