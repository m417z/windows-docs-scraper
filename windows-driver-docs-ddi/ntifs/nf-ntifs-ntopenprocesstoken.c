__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenProcessToken(
  [in]  HANDLE      ProcessHandle,
  [in]  ACCESS_MASK DesiredAccess,
  [out] PHANDLE     TokenHandle
);