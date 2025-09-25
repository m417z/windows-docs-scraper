__kernel_entry NTSYSCALLAPI NTSTATUS NtRollforwardTransactionManager(
  [in]           HANDLE         TransactionManagerHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);