NTSYSCALLAPI NTSTATUS ZwCommitEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);