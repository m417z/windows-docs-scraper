NTSYSAPI NTSTATUS ZwOpenKey(
  [out] PHANDLE            KeyHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes
);