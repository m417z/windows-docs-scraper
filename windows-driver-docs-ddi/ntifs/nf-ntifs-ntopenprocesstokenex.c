__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenProcessTokenEx(
  [in]  HANDLE      ProcessHandle,
  [in]  ACCESS_MASK DesiredAccess,
  [in]  ULONG       HandleAttributes,
  [out] PHANDLE     TokenHandle
);