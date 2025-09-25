__kernel_entry NTSYSCALLAPI NTSTATUS NtCommitEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);