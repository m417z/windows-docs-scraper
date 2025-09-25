typedef struct _SYMBOL_INFO_EX {
  ULONG   SizeOfStruct;
  ULONG   TypeOfInfo;
  ULONG64 Offset;
  ULONG   Line;
  ULONG   Displacement;
  ULONG   Reserved[4];
} SYMBOL_INFO_EX, *PSYMBOL_INFO_EX;