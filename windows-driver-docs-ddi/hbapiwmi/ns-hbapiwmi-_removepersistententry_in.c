typedef struct _RemovePersistentEntry_IN {
  UCHAR               PortWWN[8];
  HBAFCPBindingEntry2 Binding;
} RemovePersistentEntry_IN, *PRemovePersistentEntry_IN;