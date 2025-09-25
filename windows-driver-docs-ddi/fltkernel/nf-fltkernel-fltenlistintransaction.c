NTSTATUS FLTAPI FltEnlistInTransaction(
  [in] PFLT_INSTANCE     Instance,
  [in] PKTRANSACTION     Transaction,
  [in] PFLT_CONTEXT      TransactionContext,
  [in] NOTIFICATION_MASK NotificationMask
);