NTSYSCALLAPI NTSTATUS ZwPrepareEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);