PVOID MmAllocateContiguousNodeMemory(
  [in]           SIZE_T           NumberOfBytes,
  [in]           PHYSICAL_ADDRESS LowestAcceptableAddress,
  [in]           PHYSICAL_ADDRESS HighestAcceptableAddress,
  [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
  [in]           ULONG            Protect,
  [in]           NODE_REQUIREMENT PreferredNode
);