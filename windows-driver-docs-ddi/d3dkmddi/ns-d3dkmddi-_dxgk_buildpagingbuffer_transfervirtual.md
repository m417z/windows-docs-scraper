# _DXGK_BUILDPAGINGBUFFER_TRANSFERVIRTUAL structure

## Description

**DXGK_BUILDPAGINGBUFFER_TRANSFERVIRTUAL** is used as part of an allocation transfer operation.

## Members

### `hAllocation`

Kernel mode driver handle of the transferred allocation content. The handle is returned from [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation). The allocation properties are needed to perform special transfers (as swizzle, de-swizzle, etc.).

### `AllocationOffsetInBytes`

The offset in bytes from the start of the allocation being transferred. The offset should not be added to **SourceVirtualAddress** or **DesinationVirtualAddress**.

### `TransferSizeInBytes`

The number of bytes to transfer.

### `SourceVirtualAddress`

The virtual address of the source in the context of the paging process.

### `DestinationVirtualAddress`

The virtual address of the destination in the context of the paging process.

### `SourcePageTable`

The GPU virtual address of the page table that is used to map the **SourceVirtualAddress** address.

**Note** The address is valid only when the **DXGK_GPUMMUCAPS.LegacyBehaviors.SourcePageTableVaInTransfer** cap is set.

### `TransferDirection`

The [DXGK_MEMORY_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_memory_transfer_direction) structure describing the operation.

### `Flags`

The [DXGK_TRANSFERVIRTUALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_transfervirtualflags) structure describing the operation.

### `DestinationPageTable`

The GPU virtual address of the page table that is used to map the **DestinationVirtualAddress** address. The address is valid only when the **DXGK_GPUMMUCAPS.LegacyBehaviors.SourcePageTableVaInTransfer** cap is set.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DXGK_MEMORY_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_memory_transfer_direction)

[DXGK_TRANSFERVIRTUALFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_transfervirtualflags)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)