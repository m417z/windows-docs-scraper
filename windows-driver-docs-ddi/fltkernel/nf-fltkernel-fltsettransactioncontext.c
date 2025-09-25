NTSTATUS FLTAPI FltSetTransactionContext(
  [in]            PFLT_INSTANCE             Instance,
  [in]            PKTRANSACTION             Transaction,
  [in]            FLT_SET_CONTEXT_OPERATION Operation,
  [in]            PFLT_CONTEXT              NewContext,
  [out, optional] PFLT_CONTEXT              *OldContext
);