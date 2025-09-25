IOMMU_MAP_LOGICAL_RANGE IommuMapLogicalRange;

NTSTATUS IommuMapLogicalRange(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] ULONG Permissions,
  [_In_] PMDL Mdl,
  [_In_] ULONGLONG LogicalAddress
)
{...}