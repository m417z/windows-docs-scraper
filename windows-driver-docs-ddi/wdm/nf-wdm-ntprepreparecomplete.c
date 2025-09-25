__kernel_entry NTSYSCALLAPI NTSTATUS NtPrePrepareComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);