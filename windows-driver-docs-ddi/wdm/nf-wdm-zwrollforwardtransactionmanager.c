NTSYSCALLAPI NTSTATUS ZwRollforwardTransactionManager(
  [in]           HANDLE         TransactionManagerHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);