typedef struct _DEBUG_MODULE_PARAMETERS {
  ULONG64 Base;
  ULONG   Size;
  ULONG   TimeDateStamp;
  ULONG   Checksum;
  ULONG   Flags;
  ULONG   SymbolType;
  ULONG   ImageNameSize;
  ULONG   ModuleNameSize;
  ULONG   LoadedImageNameSize;
  ULONG   SymbolFileNameSize;
  ULONG   MappedImageNameSize;
  ULONG64 Reserved[2];
} DEBUG_MODULE_PARAMETERS, *PDEBUG_MODULE_PARAMETERS;