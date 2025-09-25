NTSYSAPI NTSTATUS ZwOpenKeyEx(
  [out] PHANDLE            KeyHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in]  ULONG              OpenOptions
);