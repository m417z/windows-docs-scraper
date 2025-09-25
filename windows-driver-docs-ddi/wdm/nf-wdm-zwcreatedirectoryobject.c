NTSYSAPI NTSTATUS ZwCreateDirectoryObject(
  [out] PHANDLE            DirectoryHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes
);