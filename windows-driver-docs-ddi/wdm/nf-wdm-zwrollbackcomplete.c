NTSYSCALLAPI NTSTATUS ZwRollbackComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);