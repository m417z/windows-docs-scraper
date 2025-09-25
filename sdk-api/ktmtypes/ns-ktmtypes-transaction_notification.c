typedef struct _TRANSACTION_NOTIFICATION {
  PVOID         TransactionKey;
  ULONG         TransactionNotification;
  LARGE_INTEGER TmVirtualClock;
  ULONG         ArgumentLength;
} TRANSACTION_NOTIFICATION, *PTRANSACTION_NOTIFICATION;