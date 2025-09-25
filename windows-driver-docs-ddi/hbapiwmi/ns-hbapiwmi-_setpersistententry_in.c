typedef struct _SetPersistentEntry_IN {
  UCHAR               PortWWN[8];
  HBAFCPBindingEntry2 Binding;
} SetPersistentEntry_IN, *PSetPersistentEntry_IN;