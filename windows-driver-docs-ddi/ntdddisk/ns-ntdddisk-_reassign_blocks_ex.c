typedef struct _REASSIGN_BLOCKS_EX {
  USHORT        Reserved;
  USHORT        Count;
  LARGE_INTEGER BlockNumber[1];
} REASSIGN_BLOCKS_EX, *PREASSIGN_BLOCKS_EX;