NTSYSAPI NTSTATUS ZwOpenSymbolicLinkObject(
  [out] PHANDLE            LinkHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes
);