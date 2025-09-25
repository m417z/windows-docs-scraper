## Description

Deletes an existing domain. The domain must contain no devices in order to be successfully deleted.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain to be deleted.

## Return value

Return **STATUS_SUCCESS** if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This can be called on any **IOMMU_DMA_DOMAIN** that was created through either the [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) or [**DMA_IOMMU_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface).

## See also

[IOMMU_DOMAIN_CREATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)