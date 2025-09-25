## Description

Detaches a device from an existing domain.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `PhysicalDeviceObject` [_In_]

A pointer the physical device object (PDO) in the device stack of the device.

### `InputMappingId` [_In_]

The input mapping for the device's desired stream.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

It is driver's responsibility to ensure that this function is not called concurrently with IOMMU_DOMAIN_ATTACH_DEVICE or IOMMU_SET_DEVICE_FAULT_REPORTING calls on the same device.

InputMappingId is used only for ACPI-enumerated devices on ARM64. For all other cases, this value must be zero.

If multiple devices are simultaneously attached using the _MappingCount_ value specified in the [_IOMMU_DOMAIN_ATTACH_DEVICE_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device) call, then those devices can only be detached as a group by specifying an _InputMappingId_ value that is equal to the _InputMappingIdBase_ value of [_IOMMU_DOMAIN_ATTACH_DEVICE_] used when attaching.

This is deprecated. Consider using [**IOMMU_DOMAIN_DETACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device_ex) and [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex).

## See also