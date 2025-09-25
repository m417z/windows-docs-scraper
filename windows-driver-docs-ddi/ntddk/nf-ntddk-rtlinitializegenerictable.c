NTSYSAPI VOID RtlInitializeGenericTable(
  [out]          PRTL_GENERIC_TABLE            Table,
  [in]           PRTL_GENERIC_COMPARE_ROUTINE  CompareRoutine,
  [in]           PRTL_GENERIC_ALLOCATE_ROUTINE AllocateRoutine,
  [in]           PRTL_GENERIC_FREE_ROUTINE     FreeRoutine,
  [in, optional] PVOID                         TableContext
);