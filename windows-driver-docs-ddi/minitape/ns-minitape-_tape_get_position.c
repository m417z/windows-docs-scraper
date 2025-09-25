typedef struct _TAPE_GET_POSITION {
  ULONG         Type;
  ULONG         Partition;
  LARGE_INTEGER Offset;
} TAPE_GET_POSITION, *PTAPE_GET_POSITION;