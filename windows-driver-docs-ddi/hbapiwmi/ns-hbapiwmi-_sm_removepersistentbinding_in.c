typedef struct _SM_RemovePersistentBinding_IN {
  UCHAR                 HbaPortWWN[8];
  UCHAR                 DomainPortWWN[8];
  ULONG                 EntryCount;
  MS_SMHBA_BINDINGENTRY Entry[1];
} SM_RemovePersistentBinding_IN, *PSM_RemovePersistentBinding_IN;