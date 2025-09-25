## Description

Deletes the provided opaque token representing the **IOMMU_DMA_DEVICE**.

## Parameters

### `DmaDevice`

[*In*] A pointer to the opaque token representing the **IOMMU_DMA_DEVICE** to be deleted.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_RESOURCE_IN_USE** | The device is still attached to a domain. Callers are responsible for calling [**DetachDeviceEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device_ex) before calling `DeleteDevice`. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The caller must ensure that the **IOMMU_DMA_DEVICE** is detached from any domain it was previously attached to before the caller attempts to delete and free the device.

## See also

[**IOMMU_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_create)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)