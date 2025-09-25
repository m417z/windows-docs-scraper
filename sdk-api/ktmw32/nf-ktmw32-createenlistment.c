HANDLE CreateEnlistment(
  [in, optional] LPSECURITY_ATTRIBUTES lpEnlistmentAttributes,
  [in]           HANDLE                ResourceManagerHandle,
  [in]           HANDLE                TransactionHandle,
  [in]           NOTIFICATION_MASK     NotificationMask,
  [in, optional] DWORD                 CreateOptions,
  [in, optional] PVOID                 EnlistmentKey
);