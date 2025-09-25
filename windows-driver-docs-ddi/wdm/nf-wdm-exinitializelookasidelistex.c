NTSTATUS ExInitializeLookasideListEx(
  [out]          PLOOKASIDE_LIST_EX    Lookaside,
  [in, optional] PALLOCATE_FUNCTION_EX Allocate,
  [in, optional] PFREE_FUNCTION_EX     Free,
  [in]           POOL_TYPE             PoolType,
  [in]           ULONG                 Flags,
  [in]           SIZE_T                Size,
  [in]           ULONG                 Tag,
  [in]           USHORT                Depth
);