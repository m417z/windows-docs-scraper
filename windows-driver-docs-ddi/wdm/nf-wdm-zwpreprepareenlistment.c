NTSYSCALLAPI NTSTATUS ZwPrePrepareEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);