IOMMU_SET_DEVICE_FAULT_REPORTING_EX IommuSetDeviceFaultReportingEx;

NTSTATUS IommuSetDeviceFaultReportingEx(
  PIOMMU_DMA_DEVICE DmaDevice,
  ULONG InputMappingIdBase,
  BOOLEAN Enable,
  PDEVICE_FAULT_CONFIGURATION FaultConfig
)
{...}