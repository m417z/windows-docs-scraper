__kernel_entry NTSYSCALLAPI NTSTATUS NtCommitComplete(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);