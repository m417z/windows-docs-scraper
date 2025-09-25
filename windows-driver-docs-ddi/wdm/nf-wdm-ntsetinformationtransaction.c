__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationTransaction(
  [in] HANDLE                        TransactionHandle,
  [in] TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
  [in] PVOID                         TransactionInformation,
  [in] ULONG                         TransactionInformationLength
);