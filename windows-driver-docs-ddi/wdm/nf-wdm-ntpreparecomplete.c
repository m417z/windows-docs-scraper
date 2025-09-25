__kernel_entry NTSYSCALLAPI NTSTATUS NtPrepareComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);