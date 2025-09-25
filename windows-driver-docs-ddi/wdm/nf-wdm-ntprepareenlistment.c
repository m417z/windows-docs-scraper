__kernel_entry NTSYSCALLAPI NTSTATUS NtPrepareEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);