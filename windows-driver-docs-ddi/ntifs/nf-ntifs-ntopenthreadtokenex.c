__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenThreadTokenEx(
  [in]  HANDLE      ThreadHandle,
  [in]  ACCESS_MASK DesiredAccess,
  [in]  BOOLEAN     OpenAsSelf,
  [in]  ULONG       HandleAttributes,
  [out] PHANDLE     TokenHandle
);