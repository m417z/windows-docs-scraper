IOMMU_PASID_DEVICE_CREATE IommuPasidDeviceCreate;

NTSTATUS IommuPasidDeviceCreate(
  PIOMMU_DMA_DEVICE DmaDevice,
  PIOMMU_DMA_PASID_DEVICE *PasidDeviceOut,
  PULONG AsidOut
)
{...}