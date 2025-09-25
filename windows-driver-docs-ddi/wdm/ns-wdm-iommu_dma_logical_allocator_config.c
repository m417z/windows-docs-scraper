typedef struct _IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG {
  IOMMU_DMA_LOGICAL_ALLOCATOR_TYPE LogicalAllocatorType;
  union {
    struct {
      ULONG AddressWidth;
    } BuddyAllocatorConfig;
  };
} IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG, *PIOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG;