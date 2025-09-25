IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE IommuReserveLogicalAddressRange;

NTSTATUS IommuReserveLogicalAddressRange(
  [in]           PIOMMU_DMA_DOMAIN Domain,
  [in]           SIZE_T Size,
  [in, optional] PIOMMU_DMA_LOGICAL_ADDRESS ExplicitLogicalAddress,
  [in, optional] PIOMMU_DMA_LOGICAL_ADDRESS MinLogicalAddress,
  [in, optional] PIOMMU_DMA_LOGICAL_ADDRESS MaxLogicalAddress,
  [out]          PIOMMU_DMA_LOGICAL_ADDRESS_TOKEN *LogicalAddressToken
)
{...}