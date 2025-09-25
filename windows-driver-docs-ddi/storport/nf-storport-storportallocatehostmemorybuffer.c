ULONG StorPortAllocateHostMemoryBuffer(
  [in]           PVOID            HwDeviceExtension,
  [in]           SIZE_T           MinimumBytes,
  [in]           SIZE_T           PreferredBytes,
  [in]           ULONGLONG        UtilizationBytes,
  [in]           ULONG            AlignmentBytes,
  [in]           PHYSICAL_ADDRESS LowestAcceptableAddress,
  [in]           PHYSICAL_ADDRESS HighestAcceptableAddress,
  [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
  [in, out]      PACCESS_RANGE    PhysicalAddressRanges,
  [in, out]      PULONG           PhysicalAddressRangeCount
);