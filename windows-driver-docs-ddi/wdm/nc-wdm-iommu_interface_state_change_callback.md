## Description

This routine is invoked whenever there has been a system state change that affects a [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex).

## Parameters

### `StateChange`

[*In*] A pointer to the state information that indicates which states have changed. See [**IOMMU_INTERFACE_STATE_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change).

### `Context`

[*In*, optional] An optional caller-specified context that matches the optional context passed in when registering an IOMMU Interface state change callback through [**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback).

## Remarks

This callback should be registered via [**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback). It will be immediately invoked upon registration (to avoid race conditions) and whenever a system state change has occurred. The callback owner should not assume the state and should always check the provided state information in [**IOMMU_INTERFACE_STATE_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change).

It is the callback owner's responsibility to unregister the callback, using [**IOMMU_UNREGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unregister_interface_state_change_callback), before disposing of an [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) or **IOMMU_DMA_DEVICE**.

## See also

[**IOMMU_INTERFACE_STATE_CHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change)

[**IOMMU_INTERFACE_STATE_CHANGE_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change_fields)

[**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback)

[**IOMMU_UNREGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unregister_interface_state_change_callback)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)