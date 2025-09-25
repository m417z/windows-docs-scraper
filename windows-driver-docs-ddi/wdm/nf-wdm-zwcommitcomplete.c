NTSYSCALLAPI NTSTATUS ZwCommitComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);