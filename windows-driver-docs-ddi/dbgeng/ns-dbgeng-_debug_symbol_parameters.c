typedef struct _DEBUG_SYMBOL_PARAMETERS {
  ULONG64 Module;
  ULONG   TypeId;
  ULONG   ParentSymbol;
  ULONG   SubElements;
  ULONG   Flags;
  ULONG64 Reserved;
} DEBUG_SYMBOL_PARAMETERS, *PDEBUG_SYMBOL_PARAMETERS;