NTSTATUS FLTAPI FltAllocateContext(
  [in]  PFLT_FILTER      Filter,
  [in]  FLT_CONTEXT_TYPE ContextType,
  [in]  SIZE_T           ContextSize,
  [in]  POOL_TYPE        PoolType,
  [out] PFLT_CONTEXT     *ReturnedContext
);