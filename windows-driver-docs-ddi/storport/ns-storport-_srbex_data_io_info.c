typedef struct _SRBEX_DATA_IO_INFO {
  SRBEXDATATYPE Type;
  ULONG         Length;
  ULONG         Flags;
  ULONG         Key;
  ULONG         RWLength;
  BOOLEAN       IsWriteRequest;
  UCHAR         CachePriority;
  UCHAR         Reserved[2];
  ULONG         Reserved1[2];
} SRBEX_DATA_IO_INFO, *PSRBEX_DATA_IO_INFO;