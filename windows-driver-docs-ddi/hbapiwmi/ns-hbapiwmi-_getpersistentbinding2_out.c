typedef struct _GetPersistentBinding2_OUT {
  ULONG               HBAStatus;
  ULONG               TotalEntryCount;
  ULONG               OutEntryCount;
  HBAFCPBindingEntry2 Bindings[1];
} GetPersistentBinding2_OUT, *PGetPersistentBinding2_OUT;