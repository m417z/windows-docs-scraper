__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateTransaction(
  [out]          PHANDLE            TransactionHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] LPGUID             Uow,
  [in, optional] HANDLE             TmHandle,
  [in, optional] ULONG              CreateOptions,
  [in, optional] ULONG              IsolationLevel,
  [in, optional] ULONG              IsolationFlags,
  [in, optional] PLARGE_INTEGER     Timeout,
  [in, optional] PUNICODE_STRING    Description
);