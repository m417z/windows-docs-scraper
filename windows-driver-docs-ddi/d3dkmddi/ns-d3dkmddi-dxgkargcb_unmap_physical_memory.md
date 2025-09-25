## Description

The **DXGKARGCB_UNMAP_PHYSICAL_MEMORY** structure contains information about the physical memory object from which the CPU-visible address is being unmapped by the [**DXGKCB_UNMAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapphysicalmemory) callback function.

## Members

### `hPhysicalMemoryObject`

The physical memory object from which the CPU-visible address is being unmapped.

### `pBaseAddress`

The base address returned from [**DXGKCB_MAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory) that is being unmapped.

### `Size`

The size, in bytes, of the mapped region. This should match the mapped **Size** parameter that was output from the corresponding map call.

## Remarks

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGKCB_MAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory)

[**DXGKCB_UNMAPPHYSICALMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapphysicalmemory)