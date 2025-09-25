## Description

Describes the domain types that can be created and interacted with via the [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex).

## Constants

### `DomainTypeTranslate`

The standard remapping domain. The HAL/Hypervisor will create a domain structure and page table for holding logical address mappings.

### `DomainTypePassThrough`

Represents a passthrough domain. Calls to map and unmap are not necessary. Depending on the DMAGuard policy of the machine, this domain may not be available.

### `DomainTypeUnmanaged`

This is a remapping domain in which the page table is owned by the caller. The caller is responsible for interacting with the IOMMU Interface to provide its page table as well as performing necessary IOMMU TLB flushes.

### `DomainTypeTranslateS1`

Defines the **DomainTypeTranslateS1** constant.

### `DomainTypeMax`

Invalid domain type.

## Remarks

## See also

[**IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)