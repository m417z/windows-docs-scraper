PFLT_TRANSACTION_NOTIFICATION_CALLBACK PfltTransactionNotificationCallback;

NTSTATUS PfltTransactionNotificationCallback(
  [in] PCFLT_RELATED_OBJECTS FltObjects,
  [in] PFLT_CONTEXT TransactionContext,
  [in] ULONG NotificationMask
)
{...}