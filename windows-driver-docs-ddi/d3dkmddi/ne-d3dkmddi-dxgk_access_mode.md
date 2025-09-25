## Description

**DXGK_ACCESS_MODE** describes the access mode that [**DxgkCbMapPhysicalMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory) will provide when doing a mapping.

## Constants

### `DXGK_ACCESS_MODE_KERNEL_MODE`

The resulting mapping will be a kernel-mode virtual address. If the **hPhysicalMemoryObject** returned by [**DxgkCbCreatePhysicalMemoryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject) is of type **DXGK_PHYSICAL_MEMORY_TYPE_IO_SPACE**, then **AccessMode** must be KernelMode.

### `DXGK_ACCESS_MODE_USER_MODE`

The resulting mapping will be made in the context of the current process. The caller is expected to be in the context of the correct process during both map and unmap.

## Remarks

**DXGK_ACCESS_MODE** is provided in the [**DXGKARGCB_MAP_PHYSICAL_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_map_physical_memory) structure that is passed to [**DxgkCbMapPhysicalMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory).

## See also

[**DXGKARGCB_MAP_PHYSICAL_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_map_physical_memory)

[**DxgkCbCreatePhysicalMemoryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createphysicalmemoryobject)

[**DxgkCbMapPhysicalMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapphysicalmemory)

[**DxgkCbUnmapPhysicalMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapphysicalmemory)