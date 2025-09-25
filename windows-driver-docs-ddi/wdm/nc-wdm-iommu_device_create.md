## Description

Takes a physical device object and creates an opaque token representing the **IOMMU_DMA_DEVICE** that can be used with the IOMMU interface APIs.

## Parameters

### `DeviceObject`

[*In*] A pointer to the physical device object of the device that the created **IOMMU_DMA_DEVICE** will represent.

### `DeviceConfig`

[*In*, optional] An optional pointer to a list of configurations that may be needed for device creation, depending on the system. Currently, this is required for ACPI devices on ARM64.

### `DmaDeviceOut`

[*Out*] A pointer to the opaque token representing the created **IOMMU_DMA_DEVICE**.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The provided PDO represents a device that is not behind an IOMMU. |
| **STATUS_INVALID_PARAMETER_2** | The provided inputs do not match system support. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed to allocate resources required for an **IOMMU_DMA_DEVICE** structure. |
| **STATUS_UNSUCCESSFUL** | The underlying IOMMU Interface is not correctly implemented for the `GetDeviceId` function. |
| **STATUS_NOT_FOUND** | The provided PDO represents a device that is not behind an IOMMU.<br><br>If the device is not found behind an IOMMU then it should already have direct physical memory access and the platform is not DMA Guard compliant. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

ACPI devices on ARM64 systems must provide input mappings through the `DeviceConfig` parameter. All other device types on ARM64 systems and any device on non-ARM64 systems should **NOT** provide any device configurations; otherwise, the call will fail on **STATUS_INVALID_PARAMETER_2**.

## See also

[**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration)

[**IOMMU_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_delete)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)