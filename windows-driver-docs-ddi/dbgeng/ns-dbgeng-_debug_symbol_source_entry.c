typedef struct _DEBUG_SYMBOL_SOURCE_ENTRY {
  ULONG64 ModuleBase;
  ULONG64 Offset;
  ULONG64 FileNameId;
  ULONG64 EngineInternal;
  ULONG   Size;
  ULONG   Flags;
  ULONG   FileNameSize;
  ULONG   StartLine;
  ULONG   EndLine;
  ULONG   StartColumn;
  ULONG   EndColumn;
  ULONG   Reserved;
} DEBUG_SYMBOL_SOURCE_ENTRY, *PDEBUG_SYMBOL_SOURCE_ENTRY;