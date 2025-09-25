typedef struct _KSSTREAM_POINTER_OFFSET {
  union {
    PUCHAR     Data;
    PKSMAPPING Mappings;
  };
  PUCHAR Data;
  PVOID  Alignment;
  ULONG  Count;
  ULONG  Remaining;
} KSSTREAM_POINTER_OFFSET, *PKSSTREAM_POINTER_OFFSET;