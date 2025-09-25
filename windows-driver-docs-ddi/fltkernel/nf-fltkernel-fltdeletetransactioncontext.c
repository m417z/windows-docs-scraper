NTSTATUS FLTAPI FltDeleteTransactionContext(
  [in]            PFLT_INSTANCE Instance,
  [in]            PKTRANSACTION Transaction,
  [out, optional] PFLT_CONTEXT  *OldContext
);