__kernel_entry NTSYSCALLAPI NTSTATUS NtRollbackTransaction(
  [in] HANDLE  TransactionHandle,
  [in] BOOLEAN Wait
);