__kernel_entry NTSYSCALLAPI NTSTATUS NtRollbackComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);