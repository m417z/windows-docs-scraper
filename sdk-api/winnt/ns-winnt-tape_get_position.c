typedef struct _TAPE_GET_POSITION {
  DWORD         Type;
  DWORD         Partition;
  LARGE_INTEGER Offset;
} TAPE_GET_POSITION, *PTAPE_GET_POSITION;