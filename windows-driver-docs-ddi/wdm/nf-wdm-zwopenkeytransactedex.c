NTSYSAPI NTSTATUS ZwOpenKeyTransactedEx(
  [out] PHANDLE            KeyHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in]  ULONG              OpenOptions,
  [in]  HANDLE             TransactionHandle
);