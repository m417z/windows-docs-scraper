NTSYSCALLAPI NTSTATUS ZwSinglePhaseReject(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);