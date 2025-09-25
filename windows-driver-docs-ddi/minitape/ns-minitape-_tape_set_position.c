typedef struct _TAPE_SET_POSITION {
  ULONG         Method;
  ULONG         Partition;
  LARGE_INTEGER Offset;
  BOOLEAN       Immediate;
} TAPE_SET_POSITION, *PTAPE_SET_POSITION;