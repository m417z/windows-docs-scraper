typedef struct _SM_SetPersistentBinding_OUT {
  ULONG HBAStatus;
  ULONG OutStatusCount;
  ULONG EntryStatus[1];
} SM_SetPersistentBinding_OUT, *PSM_SetPersistentBinding_OUT;