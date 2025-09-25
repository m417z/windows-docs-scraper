ALLOCATE_FUNCTION_EX AllocateFunctionEx;

PVOID AllocateFunctionEx(
  [in]      POOL_TYPE PoolType,
  [in]      SIZE_T NumberOfBytes,
  [in]      ULONG Tag,
  [in, out] PLOOKASIDE_LIST_EX Lookaside
)
{...}