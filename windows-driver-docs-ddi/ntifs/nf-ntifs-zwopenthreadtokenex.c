NTSYSAPI NTSTATUS ZwOpenThreadTokenEx(
  [in]  HANDLE      ThreadHandle,
  [in]  ACCESS_MASK DesiredAccess,
  [in]  BOOLEAN     OpenAsSelf,
  [in]  ULONG       HandleAttributes,
  [out] PHANDLE     TokenHandle
);