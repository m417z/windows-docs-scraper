## Description

Attaches a device to an existing domain.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `PhysicalDeviceObject` [_In_]

A pointer the physical device object (PDO) in the device stack of the device.

### `InputMappingIdBase` [_In_]

The input mapping base for the device's desired stream.

### `MappingCount` [_In_]

The count of mappings beginning at the base.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

It is driver's responsibility to ensure that this function is not called concurrently with IOMMU_DOMAIN_DETACH_DEVICE or IOMMU_SET_DEVICE_FAULT_REPORTING calls on the same device.

_InputMappingIdBase_ and _MappingCount_ are intended only to accommodate ACPI-enumerated devices that support multiple stream IDs on ARM64. For any other device or architecture, these values must be:

- InputMappingIdBase = 0

- MappingCount = 1

This is deprecated. Consider using [**IOMMU_DOMAIN_ATTACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device_ex) and [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex).

## See also