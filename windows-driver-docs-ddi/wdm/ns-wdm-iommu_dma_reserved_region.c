typedef struct _IOMMU_DMA_RESERVED_REGION {
  struct _IOMMU_DMA_RESERVED_REGION *RegionNext;
  IOMMU_DMA_LOGICAL_ADDRESS         Base;
  SIZE_T                            NumberOfPages;
  BOOLEAN                           ShouldMap;
} IOMMU_DMA_RESERVED_REGION, *PIOMMU_DMA_RESERVED_REGION;