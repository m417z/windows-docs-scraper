IOMMU_DOMAIN_CREATE_EX IommuDomainCreateEx;

NTSTATUS IommuDomainCreateEx(
  [in]           IOMMU_DMA_DOMAIN_TYPE DomainType,
  [in]           IOMMU_DMA_DOMAIN_CREATION_FLAGS Flags,
  [in, optional] PIOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG LogicalAllocatorConfig,
  [in, optional] PIOMMU_DMA_RESERVED_REGION ReservedRegions,
  [out]          PIOMMU_DMA_DOMAIN *DomainOut
)
{...}