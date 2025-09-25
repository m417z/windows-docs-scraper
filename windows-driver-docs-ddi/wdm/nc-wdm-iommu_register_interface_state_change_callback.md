## Description

Allows the caller to register a callback to be invoked whenever any state change related to a [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) occurs.

## Parameters

### `StateChangeCallback`

[*In*]
The [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback) to be registered.

### `Context`

[*In*, optional]
An optional context that will be passed to the state change callback.

### `DmaDevice`

[*In*]
A pointer to an opaque token representing the **IOMMU_DMA_DEVICE** that will be linked to the callback.

### `StateFields`

[*In*]
A pointer to the states that a caller is registering to be notified about. See [**IOMMU_INTERFACE_STATE_CHANGE_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change_fields).

## Return value

**STATUS_SUCCESS** if the operation is successful.

Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_UNSUCCESSFUL | The routine failed to register the provided callback because the **IOMMU_DMA_DEVICE** has already been registered with a callback. |
| STATUS_INVALID_PARAMETER_4 | The caller did not indicate interest in any interface state field in `StateFields`. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Registration will always immediately invoke the callback to avoid race conditions with any notifications that invoke the callbacks. Callback owners should not assume the state when a callback is invoked and should always check that the state matches their needs.

Before disposing of a [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) or **IOMMU_DMA_DEVICE**, the owner is responsible for unregistering all its registered callbacks.

Only one callback can be registered per **IOMMU_DMA_DEVICE**.

## See also

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)

[**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback)

[**IOMMU_INTERFACE_STATE_CHANGE_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change_fields)

[**IOMMU_UNREGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unregister_interface_state_change_callback)