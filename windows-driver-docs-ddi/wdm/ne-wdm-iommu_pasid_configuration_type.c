typedef enum _IOMMU_PASID_CONFIGURATION_TYPE {
  PasidConfigTypeDefaultPasidOnly,
  PasidConfigTypePasidTaggedDma,
  PasidConfigTypeMax
} IOMMU_PASID_CONFIGURATION_TYPE, *PIOMMU_PASID_CONFIGURATION_TYPE;