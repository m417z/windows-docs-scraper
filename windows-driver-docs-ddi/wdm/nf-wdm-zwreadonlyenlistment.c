NTSYSCALLAPI NTSTATUS ZwReadOnlyEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);