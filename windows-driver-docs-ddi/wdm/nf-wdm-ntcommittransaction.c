__kernel_entry NTSYSCALLAPI NTSTATUS NtCommitTransaction(
  [in] HANDLE  TransactionHandle,
  [in] BOOLEAN Wait
);