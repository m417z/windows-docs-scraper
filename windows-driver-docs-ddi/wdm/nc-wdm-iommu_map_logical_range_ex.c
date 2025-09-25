IOMMU_MAP_LOGICAL_RANGE_EX IommuMapLogicalRangeEx;

NTSTATUS IommuMapLogicalRangeEx(
  [in]           PIOMMU_DMA_DOMAIN Domain,
  [in]           ULONG Permissions,
  [in]           PIOMMU_MAP_PHYSICAL_ADDRESS PhysicalAddressToMap,
  [in, optional] PIOMMU_DMA_LOGICAL_ADDRESS ExplicitLogicalAddress,
  [in, optional] PIOMMU_DMA_LOGICAL_ADDRESS MinLogicalAddress,
  [in, optional] PIOMMU_DMA_LOGICAL_ADDRESS MaxLogicalAddress,
  [out]          PIOMMU_DMA_LOGICAL_ADDRESS LogicalAddressOut
)
{...}