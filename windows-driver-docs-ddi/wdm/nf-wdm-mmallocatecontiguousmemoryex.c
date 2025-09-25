NTSTATUS MmAllocateContiguousMemoryEx(
  [in]           PSIZE_T          NumberOfBytes,
  [in]           PHYSICAL_ADDRESS LowestAcceptableAddress,
  [in]           PHYSICAL_ADDRESS HighestAcceptableAddress,
  [in]           PHYSICAL_ADDRESS BoundaryAddressMultiple,
  [in]           NODE_REQUIREMENT PreferredNode,
  [in]           ULONG            Protect,
  [in, optional] PVOID            PartitionObject,
  [in]           ULONG            Tag,
  [in]           ULONG            Flags,
  [out]          PVOID            *BaseAddress
);