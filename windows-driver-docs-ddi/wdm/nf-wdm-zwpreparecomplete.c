NTSYSCALLAPI NTSTATUS ZwPrepareComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);