IOMMU_UNMAP_RESERVED_LOGICAL_RANGE IommuUnmapReservedLogicalRange;

NTSTATUS IommuUnmapReservedLogicalRange(
  [in, out] PIOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT MappedSegment
)
{...}