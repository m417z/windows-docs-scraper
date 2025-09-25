typedef struct _SM_SetPersistentBinding_IN {
  UCHAR                 HbaPortWWN[8];
  UCHAR                 DomainPortWWN[8];
  ULONG                 InEntryCount;
  MS_SMHBA_BINDINGENTRY Entry[1];
} SM_SetPersistentBinding_IN, *PSM_SetPersistentBinding_IN;