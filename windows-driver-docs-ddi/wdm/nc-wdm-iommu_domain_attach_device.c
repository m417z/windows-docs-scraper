IOMMU_DOMAIN_ATTACH_DEVICE IommuDomainAttachDevice;

NTSTATUS IommuDomainAttachDevice(
  [_In_] PIOMMU_DMA_DOMAIN Domain,
  [_In_] PDEVICE_OBJECT PhysicalDeviceObject,
  [_In_] ULONG InputMappingIdBase,
  [_In_] ULONG MappingCount
)
{...}