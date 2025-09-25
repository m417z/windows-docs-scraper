NTSYSAPI NTSTATUS ZwOpenDirectoryObject(
  [out] PHANDLE            DirectoryHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes
);