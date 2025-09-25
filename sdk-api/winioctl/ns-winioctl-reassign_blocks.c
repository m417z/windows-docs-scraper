typedef struct _REASSIGN_BLOCKS {
  WORD  Reserved;
  WORD  Count;
  DWORD BlockNumber[1];
} REASSIGN_BLOCKS, *PREASSIGN_BLOCKS;