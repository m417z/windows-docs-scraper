BOOL GetNotificationResourceManager(
  [in]            HANDLE                    ResourceManagerHandle,
  [out]           PTRANSACTION_NOTIFICATION TransactionNotification,
  [in]            ULONG                     NotificationLength,
  [in, optional]  DWORD                     dwMilliseconds,
  [out, optional] PULONG                    ReturnLength
);