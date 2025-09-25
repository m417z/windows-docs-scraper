NTSTATUS TmInitializeTransactionManager(
  [in]           PRKTM            TransactionManager,
  [in, optional] PCUNICODE_STRING LogFileName,
  [in]           PGUID            TmId,
  [in, optional] ULONG            CreateOptions
);