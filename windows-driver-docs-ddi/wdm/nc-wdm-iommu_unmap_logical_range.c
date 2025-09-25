IOMMU_UNMAP_LOGICAL_RANGE IommuUnmapLogicalRange;

NTSTATUS IommuUnmapLogicalRange(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] ULONGLONG LogicalAddress,
  [_In_] ULONGLONG NumberOfPages
)
{...}