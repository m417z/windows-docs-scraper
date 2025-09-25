NTSTATUS FLTAPI FltPrePrepareComplete(
  [in]           PFLT_INSTANCE Instance,
  [in]           PKTRANSACTION Transaction,
  [in, optional] PFLT_CONTEXT  TransactionContext
);