IOMMU_MAP_IDENTITY_RANGE IommuMapIdentityRange;

NTSTATUS IommuMapIdentityRange(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] ULONG Permissions,
  [_In_] PMDL Mdl
)
{...}