IOMMU_DEVICE_QUERY_INFORMATION IommuDeviceQueryInformation;

NTSTATUS IommuDeviceQueryInformation(
  PIOMMU_DMA_DEVICE DmaDevice,
  ULONG Size,
  PULONG BytesWritten,
  PIOMMU_DMA_DEVICE_INFORMATION Buffer
)
{...}