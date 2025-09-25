## Description

This routine sets the device fault reporting state to a device already attached to a domain.

It is driver's responsibility to ensure that this function is not called concurrently with any [**IommuDomainAttachDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device) or [**IommuDomainDetachDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device) calls on the same device.

## Parameters

### `PhysicalDeviceObject` [In]

A pointer the physical device object (PDO) in the device stack of the device.

### `InputMappingIdBase` [In]

The input mapping base for the device's desired stream.

### `Enable` [In]

a BOOLEAN value that indicates whether to enable fault reporting for the device.

### `FaultConfig` [in]

Optional. A pointer to [**DEVICE_FAULT_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_fault_configuration). This is only used for enabling fault reporting.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Register your implementation of this callback function by setting **SetDeviceFaultReporting** of [_DMA_IOMMU_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface).

## See also