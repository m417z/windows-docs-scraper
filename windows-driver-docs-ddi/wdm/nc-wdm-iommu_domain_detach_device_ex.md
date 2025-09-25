## Description

Detaches a **IOMMU_DMA_DEVICE** from an existing domain.

## Parameters

### `DmaDevice` [in]

A pointer to the **IOMMU_DMA_DEVICE** to be detached.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_INVALID_PARAMETER_1 | The device could not be detached because it is not currently attached to any domain. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The caller must call `DetachDeviceEx` before attempting to attach the device to another domain.

## See also

[**IOMMU_DOMAIN_ATTACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device_ex)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)