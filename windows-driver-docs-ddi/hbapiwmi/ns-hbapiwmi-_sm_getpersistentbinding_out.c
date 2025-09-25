typedef struct _SM_GetPersistentBinding_OUT {
  ULONG                 HBAStatus;
  ULONG                 TotalEntryCount;
  ULONG                 OutEntryCount;
  MS_SMHBA_BINDINGENTRY Entry[1];
} SM_GetPersistentBinding_OUT, *PSM_GetPersistentBinding_OUT;