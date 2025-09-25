NTSYSCALLAPI NTSTATUS ZwCreateTransactionManager(
  [out]          PHANDLE            TmHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] PUNICODE_STRING    LogFileName,
  [in, optional] ULONG              CreateOptions,
  [in, optional] ULONG              CommitStrength
);