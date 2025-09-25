typedef struct _GetFcpPersistentBinding_OUT {
  ULONG              HBAStatus;
  ULONG              TotalEntryCount;
  ULONG              OutEntryCount;
  HBAFCPBindingEntry Entry[1];
} GetFcpPersistentBinding_OUT, *PGetFcpPersistentBinding_OUT;