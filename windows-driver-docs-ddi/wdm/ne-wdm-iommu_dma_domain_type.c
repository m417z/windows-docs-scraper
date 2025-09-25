typedef enum _IOMMU_DMA_DOMAIN_TYPE {
  DomainTypeTranslate,
  DomainTypePassThrough,
  DomainTypeUnmanaged,
  DomainTypeTranslateS1,
  DomainTypeMax
} IOMMU_DMA_DOMAIN_TYPE, *PIOMMU_DMA_DOMAIN_TYPE;