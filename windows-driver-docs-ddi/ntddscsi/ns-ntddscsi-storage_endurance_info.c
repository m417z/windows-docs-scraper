typedef struct _STORAGE_ENDURANCE_INFO {
  ULONG  ValidFields;
  ULONG  GroupId;
  struct {
    ULONG Shared : 1;
    ULONG Reserved : 31;
  } Flags;
  ULONG  LifePercentage;
  UCHAR  BytesReadCount[16];
  UCHAR  ByteWriteCount[16];
} STORAGE_ENDURANCE_INFO, *PSTORAGE_ENDURANCE_INFO;