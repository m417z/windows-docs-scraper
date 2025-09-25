IOMMU_DOMAIN_DETACH_DEVICE IommuDomainDetachDevice;

NTSTATUS IommuDomainDetachDevice(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] PDEVICE_OBJECT PhysicalDeviceObject,
  [_In_] ULONG InputMappingId
)
{...}