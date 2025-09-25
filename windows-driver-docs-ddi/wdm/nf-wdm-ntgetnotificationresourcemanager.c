__kernel_entry NTSYSCALLAPI NTSTATUS NtGetNotificationResourceManager(
  [in]            HANDLE                    ResourceManagerHandle,
  [out]           PTRANSACTION_NOTIFICATION TransactionNotification,
  [in]            ULONG                     NotificationLength,
  [in]            PLARGE_INTEGER            Timeout,
  [out, optional] PULONG                    ReturnLength,
  [in]            ULONG                     Asynchronous,
  [in, optional]  ULONG_PTR                 AsynchronousContext
);