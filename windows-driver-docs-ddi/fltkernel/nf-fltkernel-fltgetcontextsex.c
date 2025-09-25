NTSTATUS FLTAPI FltGetContextsEx(
  [in]  PCFLT_RELATED_OBJECTS    FltObjects,
  [in]  FLT_CONTEXT_TYPE         DesiredContexts,
  [in]  SIZE_T                   ContextsSize,
  [out] PFLT_RELATED_CONTEXTS_EX Contexts
);