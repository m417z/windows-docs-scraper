__kernel_entry NTSYSCALLAPI NTSTATUS NtRecoverEnlistment(
  [in]           HANDLE EnlistmentHandle,
  [in, optional] PVOID  EnlistmentKey
);