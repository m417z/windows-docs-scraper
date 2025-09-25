PALLOCATE_COMMON_BUFFER_WITH_BOUNDS PallocateCommonBufferWithBounds;

PVOID PallocateCommonBufferWithBounds(
  [in]           PDMA_ADAPTER DmaAdapter,
  [in, optional] PPHYSICAL_ADDRESS MinimumAddress,
  [in, optional] PPHYSICAL_ADDRESS MaximumAddress,
  [in]           ULONG Length,
  [in]           ULONG Flags,
  [in, optional] MEMORY_CACHING_TYPE *CacheType,
  [in]           NODE_REQUIREMENT PreferredNode,
  [out]          PPHYSICAL_ADDRESS LogicalAddress
)
{...}