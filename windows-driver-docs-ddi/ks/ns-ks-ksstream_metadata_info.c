typedef struct {
  ULONG BufferSize;
  ULONG UsedSize;
  PVOID Data;
  PVOID SystemVa;
  ULONG Flags;
  ULONG Reserved;
} KSSTREAM_METADATA_INFO, *PKSSTREAM_METADATA_INFO;