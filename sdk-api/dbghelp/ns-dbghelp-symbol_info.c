typedef struct _SYMBOL_INFO {
  ULONG   SizeOfStruct;
  ULONG   TypeIndex;
  ULONG64 Reserved[2];
  ULONG   Index;
  ULONG   Size;
  ULONG64 ModBase;
  ULONG   Flags;
  ULONG64 Value;
  ULONG64 Address;
  ULONG   Register;
  ULONG   Scope;
  ULONG   Tag;
  ULONG   NameLen;
  ULONG   MaxNameLen;
  CHAR    Name[1];
} SYMBOL_INFO, *PSYMBOL_INFO;