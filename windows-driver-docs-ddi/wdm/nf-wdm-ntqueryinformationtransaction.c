__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationTransaction(
  [in]            HANDLE                        TransactionHandle,
  [in]            TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
  [out]           PVOID                         TransactionInformation,
  [in]            ULONG                         TransactionInformationLength,
  [out, optional] PULONG                        ReturnLength
);