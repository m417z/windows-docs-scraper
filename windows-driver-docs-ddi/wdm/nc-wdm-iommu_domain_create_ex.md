## Description

Creates a new DMA device domain based on the provided domain type.

## Parameters

### `DomainType` [in]

Indicates the type of domain to be created. See [**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type).

### `Flags` [in]

Configuration flags for the device domain. Currently unused and must be set to 0. See [**IOMMU_DMA_DOMAIN_CREATION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_domain_creation_flags).

### `LogicalAllocatorConfig` [in, optional]

Optionally provides a logical allocator configuration to initialize a HAL-implemented logical allocator to be associated with the domain. See [**IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_allocator_config).

### `ReservedRegions` [in, optional]

Optionally provides a set of [**IOMMU_DMA_RESERVED_REGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_reserved_region) structures to be reserved during domain creation.

### `DomainOut` [out]

Returns an opaque handle to the created domain.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_INSUFFICIENT_RESOURCES | The routine failed to allocate resources required for the domain or there are not enough ASIDs for unmanaged domains. |
| STATUS_NOT_SUPPORTED | The hypervisor domain interface not available, x86 guest machine attempting to create a domain, or provided domain type is currently not allowed. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To delete a domain created by **IOMMU_DOMAIN_CREATE_EX**, use [*IOMMU_DOMAIN_DELETE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete); there currently is no Ex equivalent of domain deletion.

## See also

[**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type)

[**IOMMU_DMA_DOMAIN_CREATION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_domain_creation_flags)

[**IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_allocator_config)

[**IOMMU_DMA_RESERVED_REGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_reserved_region)

[*IOMMU_DOMAIN_DELETE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)