__kernel_entry NTSYSCALLAPI NTSTATUS NtPrePrepareEnlistment(
  [in]           HANDLE         EnlistmentHandle,
  [in, optional] PLARGE_INTEGER TmVirtualClock
);