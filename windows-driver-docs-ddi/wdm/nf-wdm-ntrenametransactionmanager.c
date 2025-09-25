__kernel_entry NTSYSCALLAPI NTSTATUS NtRenameTransactionManager(
  [in] PUNICODE_STRING LogFileName,
  [in] LPGUID          ExistingTransactionManagerGuid
);