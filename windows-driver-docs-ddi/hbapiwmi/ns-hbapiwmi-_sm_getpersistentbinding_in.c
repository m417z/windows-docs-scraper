typedef struct _SM_GetPersistentBinding_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DomainPortWWN[8];
  ULONG InEntryCount;
} SM_GetPersistentBinding_IN, *PSM_GetPersistentBinding_IN;