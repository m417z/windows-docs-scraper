IOMMU_UNMAP_IDENTITY_RANGE_EX IommuUnmapIdentityRangeEx;

NTSTATUS IommuUnmapIdentityRangeEx(
  [in] PIOMMU_DMA_DOMAIN Domain,
  [in] PIOMMU_MAP_PHYSICAL_ADDRESS MappedPhysicalAddress
)
{...}