PFLT_CONTEXT_ALLOCATE_CALLBACK PfltContextAllocateCallback;

PVOID PfltContextAllocateCallback(
  [in] POOL_TYPE PoolType,
  [in] SIZE_T Size,
  [in] FLT_CONTEXT_TYPE ContextType
)
{...}