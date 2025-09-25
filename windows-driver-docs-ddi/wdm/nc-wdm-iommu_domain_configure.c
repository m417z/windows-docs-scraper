IOMMU_DOMAIN_CONFIGURE IommuDomainConfigure;

NTSTATUS IommuDomainConfigure(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] PDOMAIN_CONFIGURATION Configuration
)
{...}