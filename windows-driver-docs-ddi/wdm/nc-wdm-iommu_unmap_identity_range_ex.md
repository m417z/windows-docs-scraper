## Description

Deletes an identity mapping created by *IOMMU_MAP_IDENTITY_RANGE_EX*.

## Parameters

### `Domain` [in]

A pointer to the **IOMMU_DMA_DOMAIN** that the identity mapped physical address belongs to. The domain must be of type *DomainTypeTranslate* or *DomainTypePassThrough*. For more information about domain types, see [IOMMU_DMA_DOMAIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type).

### `MappedPhysicalAddress` [in]

The [**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address) representing the identity mapped address to delete.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return | Description |
|--|--|
| **STATUS_INVALID_PARAMETER_1** | The domain provided is not of type *DomainTypeTranslate* or *DomainTypePassThrough* |
| **STATUS_INVALID_PARAMETER_2** | The [**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address) provided does not represent physical memory that is page-aligned and has a size that is a multiple of PAGE_SIZE. |
| **STATUS_NOT_SUPPORTED** | The provided domain contains a logical allocator that does not allow explicit logical address allocation. |

## Remarks

## See also

[IOMMU_MAP_IDENTITY_RANGE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex)

[IOMMU_DMA_DOMAIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type)

[DMA_IOMMU_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[DMA_IOMMU_INTERFACE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)

[IOMMU_MAP_PHYSICAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address)