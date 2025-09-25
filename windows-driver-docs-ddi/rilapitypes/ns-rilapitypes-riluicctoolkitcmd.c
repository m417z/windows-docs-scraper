typedef struct RILUICCTOOLKITCMD {
  DWORD cbSize;
  DWORD dwSlotIndex;
  BOOL  fTerminalResponseNeeded;
  DWORD dwDetailsSize;
  BYTE  bDetails[1];
} RILUICCTOOLKITCMD, *LPRILUICCTOOLKITCMD;