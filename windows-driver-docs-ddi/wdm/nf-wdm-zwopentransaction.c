NTSYSCALLAPI NTSTATUS ZwOpenTransaction(
  [out]          PHANDLE            TransactionHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in]           LPGUID             Uow,
  [in, optional] HANDLE             TmHandle
);