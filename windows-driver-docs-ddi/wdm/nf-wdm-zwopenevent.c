NTSYSCALLAPI NTSTATUS ZwOpenEvent(
  [out] PHANDLE            EventHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes
);