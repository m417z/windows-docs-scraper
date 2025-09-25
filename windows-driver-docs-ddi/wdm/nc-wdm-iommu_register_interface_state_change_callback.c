IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK IommuRegisterInterfaceStateChangeCallback;

NTSTATUS IommuRegisterInterfaceStateChangeCallback(
  PIOMMU_INTERFACE_STATE_CHANGE_CALLBACK StateChangeCallback,
  PVOID Context,
  PIOMMU_DMA_DEVICE DmaDevice,
  PIOMMU_INTERFACE_STATE_CHANGE_FIELDS StateFields
)
{...}