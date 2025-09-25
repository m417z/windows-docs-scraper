NTSYSAPI NTSTATUS ZwOpenFile(
  [out] PHANDLE            FileHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes,
  [out] PIO_STATUS_BLOCK   IoStatusBlock,
  [in]  ULONG              ShareAccess,
  [in]  ULONG              OpenOptions
);