__kernel_entry NTSYSCALLAPI NTSTATUS NtRollbackEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);