__kernel_entry NTSYSCALLAPI NTSTATUS NtSinglePhaseReject(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);