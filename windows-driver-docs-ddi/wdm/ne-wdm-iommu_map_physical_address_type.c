typedef enum _IOMMU_MAP_PHYSICAL_ADDRESS_TYPE {
  MapPhysicalAddressTypeMdl,
  MapPhysicalAddressTypeContiguousRange,
  MapPhysicalAddressTypePfn,
  MapPhysicalAddressTypeMax
} IOMMU_MAP_PHYSICAL_ADDRESS_TYPE, *PIOMMU_MAP_PHYSICAL_ADDRESS_TYPE;