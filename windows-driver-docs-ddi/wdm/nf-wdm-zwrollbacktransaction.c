NTSYSCALLAPI NTSTATUS ZwRollbackTransaction(
  [in] HANDLE  TransactionHandle,
  [in] BOOLEAN Wait
);