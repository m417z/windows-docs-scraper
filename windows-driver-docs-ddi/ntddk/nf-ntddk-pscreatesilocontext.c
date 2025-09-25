NTSTATUS PsCreateSiloContext(
  [in]           PESILO                        Silo,
  [in]           ULONG                         Size,
  [in]           POOL_TYPE                     PoolType,
  [in, optional] SILO_CONTEXT_CLEANUP_CALLBACK ContextCleanupCallback,
                 PVOID                         *ReturnedSiloContext
);