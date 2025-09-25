PALLOCATE_COMMON_BUFFER_EX PallocateCommonBufferEx;

PVOID PallocateCommonBufferEx(
  [in]           PDMA_ADAPTER DmaAdapter,
  [in, optional] PPHYSICAL_ADDRESS MaximumAddress,
  [in]           ULONG Length,
  [out]          PPHYSICAL_ADDRESS LogicalAddress,
  [in]           BOOLEAN CacheEnabled,
  [in]           NODE_REQUIREMENT PreferredNode
)
{...}