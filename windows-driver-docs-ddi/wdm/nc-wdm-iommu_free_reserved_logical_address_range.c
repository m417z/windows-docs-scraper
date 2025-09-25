IOMMU_FREE_RESERVED_LOGICAL_ADDRESS_RANGE IommuFreeReservedLogicalAddressRange;

NTSTATUS IommuFreeReservedLogicalAddressRange(
  [in] PIOMMU_DMA_LOGICAL_ADDRESS_TOKEN LogicalAddressToken
)
{...}