IOMMU_SET_DEVICE_FAULT_REPORTING IommuSetDeviceFaultReporting;

NTSTATUS IommuSetDeviceFaultReporting(
  [In] PDEVICE_OBJECT PhysicalDeviceObject,
  [In] ULONG InputMappingIdBase,
  [In] BOOLEAN Enable,
  [in] PDEVICE_FAULT_CONFIGURATION FaultConfig
)
{...}