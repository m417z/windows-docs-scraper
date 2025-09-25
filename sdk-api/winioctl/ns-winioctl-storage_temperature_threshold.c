typedef struct _STORAGE_TEMPERATURE_THRESHOLD {
  DWORD   Version;
  DWORD   Size;
  WORD    Flags;
  WORD    Index;
  SHORT   Threshold;
  BOOLEAN OverThreshold;
  BYTE    Reserved;
} STORAGE_TEMPERATURE_THRESHOLD, *PSTORAGE_TEMPERATURE_THRESHOLD;