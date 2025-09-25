IOMMU_DOMAIN_CREATE IommuDomainCreate;

NTSTATUS IommuDomainCreate(
  [_In_]  BOOLEAN OsManagedPageTable,
  [_Out_] PIOMMU_DMA_DOMAIN *DomainOut
)
{...}