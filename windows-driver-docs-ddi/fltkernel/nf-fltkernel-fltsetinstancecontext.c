NTSTATUS FLTAPI FltSetInstanceContext(
  [in]  PFLT_INSTANCE             Instance,
  [in]  FLT_SET_CONTEXT_OPERATION Operation,
  [in]  PFLT_CONTEXT              NewContext,
  [out] PFLT_CONTEXT              *OldContext
);