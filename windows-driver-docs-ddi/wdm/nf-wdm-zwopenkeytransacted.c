NTSYSAPI NTSTATUS ZwOpenKeyTransacted(
  [out] PHANDLE            KeyHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in]  HANDLE             TransactionHandle
);