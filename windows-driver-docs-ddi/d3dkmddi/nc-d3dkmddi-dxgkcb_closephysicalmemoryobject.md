## Description

**DXGKCB_CLOSEPHYSICALMEMORYOBJECT** closes a physical memory object.

## Parameters

### `pArgs` [in]

Pointer to a [**DXGKARGCB_CLOSE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_close_physical_memory_object) structure that contains information about the physical memory object to close.

## Remarks

If the driver chooses to specify **hAdapterMemoryObject** as part of the [**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject) call, then it is not necessary to close it via **DXGKCB_CLOSEPHYSICALMEMORYOBJECT** as well.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl) and then call **DxgkCbClosePhysicalMemoryObject** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_CLOSE_PHYSICAL_MEMORY_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_close_physical_memory_object)

[**DXGKCB_DESTROYPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroyphysicalmemoryobject)

[**DXGKCB_OPENPHYSICALMEMORYOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_openphysicalmemoryobject)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)