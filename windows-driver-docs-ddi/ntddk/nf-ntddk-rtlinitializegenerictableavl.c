NTSYSAPI VOID RtlInitializeGenericTableAvl(
  [out]          PRTL_AVL_TABLE            Table,
  [in]           PRTL_AVL_COMPARE_ROUTINE  CompareRoutine,
  [in]           PRTL_AVL_ALLOCATE_ROUTINE AllocateRoutine,
  [in]           PRTL_AVL_FREE_ROUTINE     FreeRoutine,
  [in, optional] PVOID                     TableContext
);