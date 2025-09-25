__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationTransactionManager(
  [in, optional] HANDLE                               TmHandle,
  [in]           TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
  [in]           PVOID                                TransactionManagerInformation,
  [in]           ULONG                                TransactionManagerInformationLength
);