IOMMU_FLUSH_DOMAIN_VA_LIST IommuFlushDomainVaList;

NTSTATUS IommuFlushDomainVaList(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] BOOLEAN LastLevel,
  [_In_] ULONG Number,
  [_In_] PVOID VaList
)
{...}