IOMMU_MAP_RESERVED_LOGICAL_RANGE IommuMapReservedLogicalRange;

NTSTATUS IommuMapReservedLogicalRange(
  [in, out] PIOMMU_DMA_LOGICAL_ADDRESS_TOKEN LogicalAddressToken,
  [in]      SIZE_T Offset,
  [in]      ULONG Permissions,
  [in]      PIOMMU_MAP_PHYSICAL_ADDRESS PhysicalAddressToMap,
  [out]     PIOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT MappedSegment
)
{...}