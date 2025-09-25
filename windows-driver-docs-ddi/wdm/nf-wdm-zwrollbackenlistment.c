NTSYSCALLAPI NTSTATUS ZwRollbackEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);