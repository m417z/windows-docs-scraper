__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationTransactionManager(
  [in]            HANDLE                               TransactionManagerHandle,
  [in]            TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
  [out]           PVOID                                TransactionManagerInformation,
  [in]            ULONG                                TransactionManagerInformationLength,
  [out, optional] PULONG                               ReturnLength
);