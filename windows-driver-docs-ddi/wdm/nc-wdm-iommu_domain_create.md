## Description

Creates a new DMA remapping device domain (a container for a set of page tables).

## Parameters

### `OsManagedPageTable` [_In_]

A boolean value that indicates whether the page table is managed by the caller or by the HAL.

- TRUE, indicates the HAL owns the page table.

  - Map/Unmap are available.

  - Configure/Flush are unavailable.

- FALSE indicates that the caller owns the page table.

  - Map/Unmap are unavailable.

  - Configure/Flush are available.

### `DomainOut:` [_Out_]

A pointer to IOMMU_DMA_DOMAIN variable that receives an opaque handle used to reference the domain.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This is deprecated. Consider using [*IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex) and [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex).

## See also