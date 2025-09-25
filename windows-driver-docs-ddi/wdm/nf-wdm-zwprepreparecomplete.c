NTSYSCALLAPI NTSTATUS ZwPrePrepareComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);