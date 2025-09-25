NTSYSAPI NTSTATUS ZwOpenProcessTokenEx(
  [in]  HANDLE      ProcessHandle,
  [in]  ACCESS_MASK DesiredAccess,
  [in]  ULONG       HandleAttributes,
  [out] PHANDLE     TokenHandle
);