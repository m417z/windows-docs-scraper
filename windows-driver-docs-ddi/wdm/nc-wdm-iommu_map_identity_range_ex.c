IOMMU_MAP_IDENTITY_RANGE_EX IommuMapIdentityRangeEx;

NTSTATUS IommuMapIdentityRangeEx(
  [in] PIOMMU_DMA_DOMAIN Domain,
  [in] ULONG Permissions,
  [in] PIOMMU_MAP_PHYSICAL_ADDRESS PhysicalAddressToMap
)
{...}