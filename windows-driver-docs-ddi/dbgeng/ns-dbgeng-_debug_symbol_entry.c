typedef struct _DEBUG_SYMBOL_ENTRY {
  ULONG64 ModuleBase;
  ULONG64 Offset;
  ULONG64 Id;
  ULONG64 Arg64;
  ULONG   Size;
  ULONG   Flags;
  ULONG   TypeId;
  ULONG   NameSize;
  ULONG   Token;
  ULONG   Tag;
  ULONG   Arg32;
  ULONG   Reserved;
} DEBUG_SYMBOL_ENTRY, *PDEBUG_SYMBOL_ENTRY;