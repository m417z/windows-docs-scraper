IOMMU_UNMAP_IDENTITY_RANGE IommuUnmapIdentityRange;

NTSTATUS IommuUnmapIdentityRange(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] PMDL Mdl
)
{...}