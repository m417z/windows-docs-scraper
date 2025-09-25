## Description

**DXGKCB_UNMAPPHYSICALMEMORY** unmaps a CPU-visible virtual address from the underlying physical memory.

## Parameters

### `pArgs` [in]

Pointer to a [**DXGKARGCB_UNMAP_PHYSICAL_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_unmap_physical_memory) structure that contains information about the physical memory object from which the CPU-visible address is being unmapped.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_UNMAP_PHYSICAL_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_unmap_physical_memory) and then call **DxgkCbUnmapPhysicalMemory** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKARGCB_UNMAP_PHYSICAL_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_unmap_physical_memory)

[**DXGKCB_MAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)