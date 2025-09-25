__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenThreadToken(
  [in]  HANDLE      ThreadHandle,
  [in]  ACCESS_MASK DesiredAccess,
  [in]  BOOLEAN     OpenAsSelf,
  [out] PHANDLE     TokenHandle
);