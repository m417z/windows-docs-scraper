typedef struct PcCard_Des_s {
  DWORD PCD_Count;
  DWORD PCD_Type;
  DWORD PCD_Flags;
  BYTE  PCD_ConfigIndex;
  BYTE  PCD_Reserved[3];
  DWORD PCD_MemoryCardBase1;
  DWORD PCD_MemoryCardBase2;
  DWORD PCD_MemoryCardBase[PCD_MAX_MEMORY];
  WORD  PCD_MemoryFlags[PCD_MAX_MEMORY];
  BYTE  PCD_IoFlags[PCD_MAX_IO];
} PCCARD_DES, *PPCCARD_DES;