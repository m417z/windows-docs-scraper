PVOID MmAllocateContiguousMemorySpecifyCacheNode(
  [in]           SIZE_T              NumberOfBytes,
  [in]           PHYSICAL_ADDRESS    LowestAcceptableAddress,
  [in]           PHYSICAL_ADDRESS    HighestAcceptableAddress,
  [in, optional] PHYSICAL_ADDRESS    BoundaryAddressMultiple,
  [in]           MEMORY_CACHING_TYPE CacheType,
  [in]           NODE_REQUIREMENT    PreferredNode
);