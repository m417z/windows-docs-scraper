## Description

**IOMMU_INTERFACE_STATE_CHANGE** represents the IOMMU interface state at the time a state change callback is invoked. When an [**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback) is invoked, the `PresentFields` indicate which [**IOMMU_INTERFACE_STATE_CHANGE_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change_fields) have changed while the rest of the members of **IOMMU_INTERFACE_STATE_CHANGE** provide the new state.

## Members

### `PresentFields`

Indicates which IOMMU interface states have changed. If a field within this structure is set to 1, this indicates a state change for that state field.

### `AvailableDomainTypes`

Represents all the domain types currently available. Each set bit represents an available domain type: `(1 << IOMMU_DMA_DOMAIN_TYPE)`. See [**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type) for more details.

## Remarks

## See also

[**IOMMU_INTERFACE_STATE_CHANGE_FIELDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_interface_state_change_fields)

[**IOMMU_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_interface_state_change_callback)

[**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type)