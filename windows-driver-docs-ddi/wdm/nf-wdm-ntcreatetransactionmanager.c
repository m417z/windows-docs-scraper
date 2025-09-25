__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateTransactionManager(
  [out]          PHANDLE            TmHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] PUNICODE_STRING    LogFileName,
  [in, optional] ULONG              CreateOptions,
  [in, optional] ULONG              CommitStrength
);