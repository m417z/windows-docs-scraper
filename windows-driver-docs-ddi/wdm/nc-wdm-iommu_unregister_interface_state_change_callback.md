## Description

Allows the caller to deregister a registered [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback).

## Parameters

### `StateChangeCallback`

[*In*]
The [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback) to be unregistered.

### `DmaDevice`

[*In*]
A pointer to an opaque token representing the **IOMMU_DMA_DEVICE** associated with the provided callback.

## Return value

**STATUS_SUCCESS** if the operation is successful.

Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_UNSUCCESSFUL | The provided [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback) is not a registered callback. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Before disposing of a [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) or **IOMMU_DMA_DEVICE**, the owner is responsible for unregistering all its registered callbacks.

Only one callback can be registered per **IOMMU_DMA_DEVICE**.

## See also

[**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback)

[**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)