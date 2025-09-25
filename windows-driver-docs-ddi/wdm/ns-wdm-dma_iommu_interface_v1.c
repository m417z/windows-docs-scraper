typedef struct _DMA_IOMMU_INTERFACE_V1 {
  PIOMMU_DOMAIN_CREATE              CreateDomain;
  PIOMMU_DOMAIN_DELETE              DeleteDomain;
  PIOMMU_DOMAIN_ATTACH_DEVICE       AttachDevice;
  PIOMMU_DOMAIN_DETACH_DEVICE       DetachDevice;
  PIOMMU_FLUSH_DOMAIN               FlushDomain;
  PIOMMU_FLUSH_DOMAIN_VA_LIST       FlushDomainByVaList;
  PIOMMU_QUERY_INPUT_MAPPINGS       QueryInputMappings;
  PIOMMU_MAP_LOGICAL_RANGE          MapLogicalRange;
  PIOMMU_UNMAP_LOGICAL_RANGE        UnmapLogicalRange;
  PIOMMU_MAP_IDENTITY_RANGE         MapIdentityRange;
  PIOMMU_UNMAP_IDENTITY_RANGE       UnmapIdentityRange;
  PIOMMU_SET_DEVICE_FAULT_REPORTING SetDeviceFaultReporting;
  PIOMMU_DOMAIN_CONFIGURE           ConfigureDomain;
} DMA_IOMMU_INTERFACE_V1, *PDMA_IOMMU_INTERFACE_V1;