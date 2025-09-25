## Description

Queries for the available types of domains that an **IOMMU_DMA_DEVICE** is allowed to attach to, depending on environment factors, such as platform and DMA Guard Policy.

## Parameters

### `DmaDevice`

[*In*] A pointer to an opaque token representing the **IOMMU_DMA_DEVICE**.

### `AvailableDomains`

[*Out*] Returns the current domain types that are available to be created and attached to. Each set bit represents an available domain type: `(1 << IOMMU_DMA_DOMAIN_TYPE)`. See [**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type).

## Remarks

This can be used as a hint as to whether [**IOMMU_DOMAIN_ATTACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device_ex) will succeed.

If a device is not behind a DMA remapping compatible IOMMU, then no remapping domain will be available.

If DMA Guard is enabled, then passthrough domains may be available based on policy, i.e. whether the device is opted into DMA remapping, is connected externally, the screen lock state, etc.. If DMA Guard blocking is active, then passthrough domains will not be available and `AvailableDomains & (1 << DomainTypePassThrough)` will result in 0.

To be notified of when domain types are available, consider using [**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback) to register a notification callback whenever the available domain types change.

## See also

[**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type)

[**IOMMU_DOMAIN_ATTACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device_ex)

[**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)