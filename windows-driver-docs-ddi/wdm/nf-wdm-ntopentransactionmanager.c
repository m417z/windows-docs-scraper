__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenTransactionManager(
  [out]          PHANDLE            TmHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] PUNICODE_STRING    LogFileName,
  [in, optional] LPGUID             TmIdentity,
  [in, optional] ULONG              OpenOptions
);