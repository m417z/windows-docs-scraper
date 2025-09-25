BOOL GetNotificationResourceManagerAsync(
  [in]  HANDLE                    ResourceManagerHandle,
  [out] PTRANSACTION_NOTIFICATION TransactionNotification,
  [in]  ULONG                     TransactionNotificationLength,
  [out] PULONG                    ReturnLength,
  [in]  LPOVERLAPPED              lpOverlapped
);