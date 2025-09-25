__kernel_entry NTSYSCALLAPI NTSTATUS NtReadOnlyEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);